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

def is_problem_exist(database_id, commit_message, user_name):
    """
    '나(user_name)'의 기록 중에 이미 같은 제목(메시지)의 문제가 있는지 확인합니다.
    (다른 사람이 푼 건 무시합니다)
    """
    url = f"https://api.notion.com/v1/databases/{database_id}/query"
    
    # "문제이름"이 같고(AND) "푼 사람"도 나인 경우만 검색
    payload = {
        "filter": {
            "and": [
                {
                    "property": "문제이름", 
                    "title": {
                        "equals": commit_message
                    }
                },
                {
                    "property": "푼 사람",
                    "select": {
                        "equals": user_name
                    }
                }
            ]
        }
    }
    
    res = requests.post(url, json=payload, headers=headers)
    data = res.json()
    
    # 내 기록 중에 같은 문제가 있으면 True 반환
    return len(data.get("results", [])) > 0
  
if __name__ == "__main__":
    print(f"🚀 {NOTION_NAME}님의 {GITHUB_REPOSITORY} 레포지토리 확인 중...")
    
    commit = get_latest_commit()
    
    if commit:
        print(f"📌 발견된 커밋: {commit['message']}")
        
        # [중요] 중복 검사 로직
        if is_problem_exist(DATABASE_ID, commit['message'], NOTION_NAME):
            print("⚠️ 이미 등록된 문제입니다. (저장 건너뜀)")
            # 이미 풀었지만 점수를 체크하고 싶다면 여기서 별도 로직 수행 가능
        else:
            send_to_notion(commit)
    else: 
        print("❌ 커밋 정보를 가져오지 못했습니다.")