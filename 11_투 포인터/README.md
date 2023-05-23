# 투 포인터 (Two Pointer)

[메인으로 돌아가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4)

## 💻 튜터링

### 라이브 코딩

|                                 문제 번호                                 |                                      문제 이름                                       |                                       난이도                                       |  풀이 링크   |    분류    |
| :-----------------------------------------------------------------------: | :----------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :----------: | :--------: |
|  <a href="https://www.acmicpc.net/problem/11659" target="_blank">11659</a>  |    <a href="https://www.acmicpc.net/problem/11659" target="_blank">구간 합 구하기4</a>    | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>  | [바로가기]() |     누적 합     |
| <a href="https://www.acmicpc.net/problem/21921" target="_blank">21921</a> |   <a href="https://www.acmicpc.net/problem/21921" target="_blank">블로그</a>    | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/> | [바로가기]() |     누적 합, 슬라이딩 윈도우     |
| <a href="https://www.acmicpc.net/problem/2470" target="_blank">2470</a> | <a href="https://www.acmicpc.net/problem/2470" target="_blank">두 용액</a> | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/> | [바로가기]() | 투 포인터 |

## ✏️ 과제

### 마감기한

~ 5 / 16 (화) 18:59 - 과제 제출 </br>
~ 5 / 18 (목) 23:59 - 추가 제출 </br>

### 필수

|                                 문제 번호                                 |                                       문제 이름                                        |                                       난이도                                       | 풀이 링크 |            분류            |
| :-----------------------------------------------------------------------: | :------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :-------: | :------------------------: |
| <a href="https://www.acmicpc.net/problem/14503" target="_blank">14503</a> | <a href="https://www.acmicpc.net/problem/14503" target="_blank">로봇 청소기</a> | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/> |  [C++]()  | 구현, 시뮬레이션 |
| <a href="https://www.acmicpc.net/problem/20922" target="_blank">20922</a> |     <a href="https://www.acmicpc.net/problem/20922" target="_blank">겹치는 건 싫어</a>     | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/>  |  [C++]()  |             투 포인터             |
|  <a href="https://www.acmicpc.net/problem/20437" target="_blank">20437</a>  |       <a href="https://www.acmicpc.net/problem/20437" target="_blank">문자열 게임 2</a>       | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/> |  [C++]()  |             슬라이딩 윈도우             |

### 도전

|                                                 문제 번호                                                  |                                                      문제 이름                                                      |                                       난이도                                       | 풀이 링크 | 분류 |
| :--------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :-------: | :--: |
|                  <a href="https://www.acmicpc.net/problem/13422" target="_blank">13422</a>                   |                       <a href="https://www.acmicpc.net/problem/13422" target="_blank">도둑</a>                       | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> |  [C++]()  |  투 포인터, 슬라이딩 윈도우  |
| <a href="https://www.acmicpc.net/problem/2473" target="_blank">2473</a> | <a href="https://www.acmicpc.net/problem/2473" target="_blank">세 용액</a> |   <img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>             |  [C++]()  |  투 포인터  |
---

### 힌트

<details>
<summary>로봇 청소기</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;청소할 공간이 없을 때까지 계속해서 청소하는 방식이네요. 배웠던 알고리즘과 비슷해보이지 않나요? 방향에 유의하여 풀어보아요.
</div>
</details>

<details>
<summary>겹치는 건 싫어</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;두 포인터를 맨 왼쪽에 두고 오른쪽에 있는 숫자를 현재 수열에 추가할 수 있을지 없을지를 생각하며 탐색해볼까요?
</div>
</details>

<details>
<summary>문자열 게임 2</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;특정 문자가 k개 포함되면서 양쪽 끝이 해당 문자로 같아야 한다고 하니 우리에게 필요한 건 각 문자의 위치겠네요! 슬라이딩 윈도우를 사용해서 풀이해줘야 할 것 같은데, 윈도우의 크기는 얼마여야 할까요?
</div>
</details>

<details>
<summary>도둑</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;마을이 원이라는 점에 주의하여 슬라이딩 윈도우로 훔칠 수 있는 돈을 계산해봅시다.
</div>
</details>

<details>
<summary>세 용액</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;라이브코딩에서 다뤘던 두 용액 문제에 용액 하나가 추가됐네요! 포인터 3개를 쓰기는 힘들 것 같으니 결국 투포인터를 사용해 풀이해줘야 하는데, 나머지 하나는 어떻게 하면 좋을까요? 한 용액이 반드시 포함되도록 하고 나머지 두 용액을 찾아주면 좋을 것 같네요.
</div>
</details>


---
