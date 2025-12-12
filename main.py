import requests
import datetime
import os


# Github Action이 실행될 때 자동으로 제공해주는 환경변수 (예: 'my-id/algorithm-repo')
GITHUB_REPOSITORY = os.getenv('GITHUB_REPOSITORY') 
NOTION_NAME = os.environ.get('NOTION_NAME')
NOTION_TOKEN = os.environ.get('NOTION_TOKEN')
DATABASE_ID = os.environ.get('DATABASE_ID')

headers = {
    "Authorization": f"Bearer {NOTION_TOKEN}",
    "Content-Type": "application/json",
    "Notion-Version": "2022-06-28"
}

def get_latest_commit():
    """
    현재 레포지토리의 가장 최근 커밋을 가져옵니다.
    """
    # 깃허브 API를 통해 현재 레포지토리의 커밋 목록 조회
    url = f"https://api.github.com/repos/{GITHUB_REPOSITORY}/commits"
    
    try:
        response = requests.get(url)
        commits = response.json()
        
        if isinstance(commits, list) and len(commits) > 0:
            latest = commits[0]
            return {
                "message": latest['commit']['message'],
                "link": latest['html_url'],
                "date": latest['commit']['author']['date'] # ISO 포맷
            }
        return None
    except Exception as e:
        print(f"❌ Error: {e}")
        return None

def send_to_notion(commit_data):
    # 오늘 날짜
    today_str = datetime.datetime.now().strftime("%Y-%m-%d")

    data = {
        "parent": {"database_id": DATABASE_ID},
        "properties": {
            "문제이름": { 
                "title": [{"text": {"content": commit_data['message']}}]
            },
            "푼 사람": {
                "select": {"name": NOTION_NAME}
            },
            "날짜": {
                "date": {"start": today_str}
            },
            "링크": {
                "url": commit_data['link']
            }
        }
    }
    
    res = requests.post("https://api.notion.com/v1/pages", headers=headers, json=data)
    if res.status_code == 200:
        print(f"✅ {NOTION_NAME}님 노션 등록 완료!")
    else:
        print(f"❌ 노션 전송 실패: {res.text}")

if __name__ == "__main__":
    print(f"🚀 {NOTION_NAME}님의 {GITHUB_REPOSITORY} 레포지토리 확인 중...")
    
    commit = get_latest_commit()
    
    if commit:
        # 백준허브가 올리는 커밋인지 확인 
        print(f"📌 발견된 커밋: {commit['message']}")
        send_to_notion(commit)
    else:
        print("❌ 커밋 정보를 가져오지 못했습니다.")