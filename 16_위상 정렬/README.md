# 위상 정렬 (Topological Sort)

[메인으로 돌아가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4)

## 💻 튜터링

### 라이브 코딩

|                                 문제 번호                                 |                                      문제 이름                                       |                                       난이도                                       |  풀이 링크   |    분류    |
| :-----------------------------------------------------------------------: | :----------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :----------: | :--------: |
|  <a href="https://www.acmicpc.net/problem/2252" target="_blank">2252</a>  |    <a href="https://www.acmicpc.net/problem/2252" target="_blank">줄 세우기</a>    | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>  | [바로가기]() |     위상 정렬      |
| <a href="https://www.acmicpc.net/problem/1005" target="_blank">1005</a> |   <a href="https://www.acmicpc.net/problem/1005" target="_blank">ACM Craft</a>    | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/> | [바로가기]() |     위상 정렬, DP     |
| - |   <a target="_blank">위상 정렬 DFS 풀이</a>    | - | [바로가기]() |     위상 정렬, DFS     |

## ✏️ 과제

### 필수

|                                 문제 번호                                 |                                       문제 이름                                        |                                       난이도                                       | 풀이 링크 |            분류            |
| :-----------------------------------------------------------------------: | :------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :-------: | :------------------------: |
| <a href="https://school.programmers.co.kr/learn/courses/30/lessons/60061" target="_blank">프로그래머스</a>                   |                       <a href="https://school.programmers.co.kr/learn/courses/30/lessons/60061" target="_blank">기둥과 보 설치</a>                       | **Lv.3** |  [C++]()  |  구현, 시뮬레이션  |
| <a href="https://www.acmicpc.net/problem/2623" target="_blank">2623</a> |     <a href="https://www.acmicpc.net/problem/2623" target="_blank">음악프로그램</a>     | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>  |  [C++]()  |             위상 정렬, 그래프             |
| <a href="https://www.acmicpc.net/problem/1776" target="_blank">1776</a> |     <a href="https://www.acmicpc.net/problem/1776" target="_blank">문제집</a>     | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/>  |  [C++]()  |             위상 정렬, 우선순위 큐             |

### 도전

|                                                 문제 번호                                                  |                                                      문제 이름                                                      |                                       난이도                                       | 풀이 링크 | 분류 |
| :--------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :-------: | :--: |
| <a href="https://www.acmicpc.net/problem/23632" target="_blank">23632</a> | <a href="https://www.acmicpc.net/problem/23632" target="_blank">쿠키런 킹덤</a> |   <img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/>             |  [C++]()  |  위상 정렬 |
| <a href="https://www.acmicpc.net/problem/2637" target="_blank">2637</a> | <a href="https://www.acmicpc.net/problem/2637" target="_blank">장난감 조립</a> |   <img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/>             |  [C++]()  |  위상 정렬, DP |
---

### 힌트

<details>
<summary>기둥과 보 설치</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;구조물의 설치 조건을 잘 확인해주세요! 구조물을 삭제하기 위한 조건을 일일이 나누기 어렵다면, 반대로 구조물이 삭제됐을 때 원래 붙어있던 다른 구조물이 유지될 수 있을지 확인해주면 어떨까요?
</div>
</details>

<details>
<summary>음악프로그램</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;가수들의 선후 관계가 주어져 있네요. 튜터링에서 배운 알고리즘을 이용하면 순서를 쉽게 구할 수 있을 것 같아요. 순서를 정하는 것이 불가능한 경우는 어떤 경우일까요?
</div>
</details>

<details>
<summary>문제집</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;튜터링에서 다루었던 문제에서 조건이 하나 추가된 것 같아요. 문제의 번호가 중요할 것 같아요. 자료 구조를 잘 활용하면 좋을 것 같네요.
</div>
</details>

<details>
<summary>쿠키런 킹덤</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;배웠던 위상정렬의 개념을 연관지어볼까요? 이미 지어진 건물은 자원을 생성하고, 필요한 자원이 모두 충족되면 새로운 건물을 지을 수 있네요! 어떤 자료형으로 이러한 관계를 표현할 수 있을까요? 이때 자원을 생성하는 시간은 0초라고 했으니, 사실상 건물이 지어짐과 동시에 그 건물이 생산하는 자원은 이미 확보된 것이나 다름 없겠어요! 특정 건물을 짓기위해서 여태까지 몇개의 재료만을 남기고 있는지(=충족시켰는지)를 어떤식으로 저장하면 좋을까요?
</div>
</details>

<details>
<summary>장난감 조립</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;큰 부품에서 작은 부품 순서로 접근하면 어떨까요? 기본 부품이 어떤 부품인지 구별하는 것도 중요할 것 같아요. 어렵지 않게 구분할 수 있어요. 기본 부품은 어떤 특징이 있을까요?
</div>
</details>


---
