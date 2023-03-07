# 정수론 (Number Theory)

[메인으로 돌아가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4)

## 💻 튜터링

### 라이브 코딩

|                                 문제 번호                                 |                                         문제 이름                                          |                                       난이도                                       |  풀이 링크   |        분류         |
| :-----------------------------------------------------------------------: | :----------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :----------: | :-----------------: |
|  <a href="https://www.acmicpc.net/problem/2609" target="_blank">2609</a>  | <a href="https://www.acmicpc.net/problem/2609" target="_blank">최대공약수와 최소공배수</a> | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/5.svg"/>  | [바로가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4/blob/main/03_%EC%A0%95%EC%88%98%EB%A1%A0/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/2609.cpp) |   유클리드 호제법   |
|  <a href="https://www.acmicpc.net/problem/2960" target="_blank">2960</a>  |   <a href="https://www.acmicpc.net/problem/2960" target="_blank">에라토스테네스의 체</a>   | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/7.svg"/>  | [바로가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4/blob/main/03_%EC%A0%95%EC%88%98%EB%A1%A0/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/2960.cpp) | 에라토스테네스의 체 |
| <a href="https://www.acmicpc.net/problem/16563" target="_blank">16563</a> |   <a href="https://www.acmicpc.net/problem/16563" target="_blank">어려운 소인수분해</a>    | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> | [바로가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4/blob/main/03_%EC%A0%95%EC%88%98%EB%A1%A0/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/16563.cpp) | 에라토스테네스의 체 |

## ✏️ 과제

### 마감기한

~ 3 / 7 (화) 18:59 - 과제 제출 </br>
~ 3 / 9 (목) 23:59 - 추가 제출 </br>

### 필수

|                                문제 번호                                |                                     문제 이름                                      |                                       난이도                                       | 풀이 링크 |        분류         |
| :---------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :-------: | :-----------------: |
| <a href="https://www.acmicpc.net/problem/2840" target="_blank">2840</a> |   <a href="https://www.acmicpc.net/problem/2840" target="_blank">행운의 바퀴</a>   | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/7.svg"/>  |  [C++]()  |  구현, 시뮬레이션   |
| <a href="https://www.acmicpc.net/problem/6588" target="_blank">6588</a> | <a href="https://www.acmicpc.net/problem/6588" target="_blank">골드바흐의 추측</a> | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/> |  [C++]()  | 에라토스테네스의 체 |
| <a href="https://www.acmicpc.net/problem/1735" target="_blank">1735</a> |     <a href="https://www.acmicpc.net/problem/1735" target="_blank">분수 합</a>     | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>  |  [C++]()  |   유클리드 호제법   |

### 도전

|                                문제 번호                                |                                   문제 이름                                   |                                       난이도                                       | 풀이 링크 |              분류              |
| :---------------------------------------------------------------------: | :---------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :-------: | :----------------------------: |
| <a href="https://www.acmicpc.net/problem/9421" target="_blank">9421</a> | <a href="https://www.acmicpc.net/problem/9421" target="_blank">소수상근수</a> | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/> |  [C++]()  | 에라토스테네스의 체, 소수 판정 |
| <a href="https://www.acmicpc.net/problem/2981" target="_blank">2981</a> |    <a href="https://www.acmicpc.net/problem/2981" target="_blank">검문</a>    | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> |  [C++]()  |        유클리드 호제법         |

---

### 힌트

<details>
<summary>행운의 바퀴</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;바퀴를 배열로 고정시키고, 화살표를 움직인다면 화살표는 배열의 왼쪽 방향으로 이동하겠죠? 바퀴를 돌리는 횟수가 매우 클 수도 있으니 인덱스가 음수가 되지 않도록 유의해야 해요.
</div>
</details>

<details>
<summary>골드바흐의 추측</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;b - a가 가장 큰 경우가 언제일지 잘 생각해보아요! n = a + b를 만족시키는 두 소수들을 어디서부터 탐색하면 좋을까요?
</div>
</details>

<details>
<summary>분수 합</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;기약분수는 분모와 분자가 더 이상 약분되지 않는 분수를 말하죠! 어렵게 생각하지 말고 차근차근 두 분수를 더하고 약분해줍시다.
</div>
</details>

<details>
<summary>소수상근수</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;소수를 찾았다면 상근수인지 판단하면 되겠네요. 문제에서 주어진 그대로 구현해볼까요? 각 자릿수의 제곱의 합을 구할 때, 언제 그만둬야 할지 잘 생각해봐야겠어요.

</div>
</details>

<details>
<summary>검문</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;입력으로 주어진 모든 수에 대하여 나눴을 때 나머지가 모두 같게 하는 M을 보다 효율적으로 판단해주려면 어떻게 해야 할까요? 접근이 어렵다면 각 수를 몫과 나머지로 나타내보면 좋을 것 같아요.
</div>
</details>

---
