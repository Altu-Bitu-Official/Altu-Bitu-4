# DFS & BFS

[메인으로 돌아가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4)

## 💻 튜터링

### 라이브 코딩

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/1260" target="_blank">1260</a>|<a href="https://www.acmicpc.net/problem/1260" target="_blank">DFS와 BFS</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/9.svg"/>|[C++](https://github.com/Altu-Bitu-Official/Altu-Bitu-4/blob/main/07_DFS%20%26%20BFS/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/1260.cpp)|DFS, BFS|
|<a href="https://www.acmicpc.net/problem/2606" target="_blank">2606</a>|<a href="https://www.acmicpc.net/problem/2606" target="_blank">바이러스</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>|[C++](https://github.com/Altu-Bitu-Official/Altu-Bitu-4/blob/main/07_DFS%20%26%20BFS/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/2606.cpp)|DFS, BFS|
|<a href="https://www.acmicpc.net/problem/7576" target="_blank">7576</a>|<a href="https://www.acmicpc.net/problem/7576" target="_blank">토마토</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[C++](https://github.com/Altu-Bitu-Official/Altu-Bitu-4/blob/main/07_DFS%20%26%20BFS/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/7576.cpp)|BFS|

## ✏️ 과제

### 마감기한

~ 4 / 4 (화) 18:59 - 과제 제출 </br>
~ 4 / 6 (목) 23:59 - 추가 제출 </br>

### 필수

|                                문제 번호                                |                                    문제 이름                                     |                                       난이도                                       | 풀이 링크 |       분류        |
| :---------------------------------------------------------------------: | :------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :-------: | :---------------: |
| <a href="https://www.acmicpc.net/problem/2615" target="_blank">2615</a> |     <a href="https://www.acmicpc.net/problem/2615" target="_blank">오목</a>      | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/> |  [C++]()  | 구현, 브루트 포스 |
| <a href="https://www.acmicpc.net/problem/4963" target="_blank">4963</a> |   <a href="https://www.acmicpc.net/problem/4963" target="_blank">섬의 개수</a>   | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/9.svg"/>  |  [C++]()  |     DFS, BFS      |
| <a href="https://www.acmicpc.net/problem/1325" target="_blank">1325</a> | <a href="https://www.acmicpc.net/problem/1325" target="_blank">효율적인 해킹</a> | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/> |  [C++]()  |     DFS, BFS      |

### 도전

|                                                 문제 번호                                                 |                                                   문제 이름                                                   |                                       난이도                                       | 풀이 링크 | 분류 |
| :-------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :-------: | :--: |
| <a href="https://school.programmers.co.kr/learn/courses/30/lessons/1844" target="_blank">프로그래머스</a> | <a href="https://school.programmers.co.kr/learn/courses/30/lessons/1844" target="_blank">게임 맵 최단거리</a> |                                      **Lv.2**                                      |  [C++]()  | BFS  |
|                 <a href="https://www.acmicpc.net/problem/19538" target="_blank">19538</a>                 |                   <a href="https://www.acmicpc.net/problem/19538" target="_blank">루머</a>                    | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> |  [C++]()  | BFS  |

---

### 힌트

<details>
<summary>오목</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;여섯 알 이상이 연속이면 오목으로 인정하지 않고, 딱 다섯 알이 연속인 경우에는 가장 왼쪽 위에 있는 돌을 출력한다는 조건을 잘 기억해주세요! 이 조건을 잘 응용해보면 탐색 방향도 정해볼 수 있겠네요.
</div>
</details>

<details>
<summary>섬의 개수</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;탐색을 한 번 하면 하나의 영역을 구할 수 있어요!
</div>
</details>

<details>
<summary>효율적인 해킹</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;a가 b를 신뢰할 때, b를 해킹하면 a도 해킹할 수 있어요. 인접 리스트를 이용해서 단방향 그래프를 구현해볼까요?
</div>
</details>

<details>
<summary>게임 맵 최단거리</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;최단거리를 구하는 문제네요. BFS를 사용해볼까요?
</div>
</details>

<details>
<summary>루머</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;주변인의 절반 이상이 루머를 믿을 때 본인도 루머를 믿어요! 루머를 믿는 사람은 자신의 주변인에게 루머를 "동시에" 퍼뜨리고 있다는 것을 주의해주세요.
</div>
</details>

---
