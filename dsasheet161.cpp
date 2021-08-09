int arr[MAX_CHAR] = {0};
queue<char> q;
string res = "";

for(int i = 0; i < A.length(); i++) {
arr[A[i] - 'a']++;

q.push(A[i]);

while(not q.empty()) {
if(arr[q.front() - 'a'] > 1)
q.pop();
else
break;
}

if(q.empty())
res += '#';
else {
res += q.front();
}

}

return res;