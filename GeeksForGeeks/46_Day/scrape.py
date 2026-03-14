import urllib.request
import json

url = 'https://practiceapi.geeksforgeeks.org/api/vr/problems/top-view-of-binary-tree/'
req = urllib.request.Request(url, headers={'User-Agent': 'Mozilla/5.0'})
try:
    with urllib.request.urlopen(req) as response:
        data = json.loads(response.read().decode())
        statement = data.get('results', {}).get('problem_statement', '')
        print(statement)
except Exception as e:
    print(e)
