С���и������ų�һ���������ܷ����Ƿֳ���������������(���ڻ��ϱ�������)��ʹ�������ֵĺ���ȣ�

//�����д��Ż�
T = int(input())
for m in range(T) :
a = int(input())
b = list(map(int, input().split()))
sum_b = sum(b)
c = False
if sum(b) % 2 :
print('NO')
else:
for i in range(0, a) :
for j in range(i + 1, a + 1) :
sum_d = sum(b[i:j])
if sum_d == sum_b / 2 :
print('YES')
c = True
break
elif sum_d > sum(b) / 2:
break
if c :
break
else :
print('NO')
