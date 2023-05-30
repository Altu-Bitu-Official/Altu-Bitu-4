# 최단 경로 (Shortest Path)

[메인으로 돌아가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4)

## 💻 튜터링

### 라이브 코딩

|                                 문제 번호                                 |                                      문제 이름                                       |                                       난이도                                       |  풀이 링크   |    분류    |
| :-----------------------------------------------------------------------: | :----------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :----------: | :--------: |
|  <a href="https://www.acmicpc.net/problem/1753" target="_blank">1753</a>  |    <a href="https://www.acmicpc.net/problem/1753" target="_blank">최단경로</a>    | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>  | [바로가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4/blob/main/13_%EC%B5%9C%EB%8B%A8%20%EA%B2%BD%EB%A1%9C/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/1753.cpp) |     다익스트라      |
| <a href="https://www.acmicpc.net/problem/11404" target="_blank">11404</a> |   <a href="https://www.acmicpc.net/problem/11404" target="_blank">플로이드</a>    | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> | [바로가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4/blob/main/13_%EC%B5%9C%EB%8B%A8%20%EA%B2%BD%EB%A1%9C/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/11404.cpp) |     플로이드-워셜     |
| <a href="https://www.acmicpc.net/problem/11657" target="_blank">11657</a> |   <a href="https://www.acmicpc.net/problem/11657" target="_blank">타임머신</a>    | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> | [바로가기](https://github.com/Altu-Bitu-Official/Altu-Bitu-4/blob/main/13_%EC%B5%9C%EB%8B%A8%20%EA%B2%BD%EB%A1%9C/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/11657.cpp) |     벨만-포드     |

## ✏️ 과제

### 마감기한

~ 5 / 30 (화) 18:59 - 과제 제출 </br>
~ 6 / 1 (목) 23:59 - 추가 제출 </br>

### 필수

|                                 문제 번호                                 |                                       문제 이름                                        |                                       난이도                                       | 풀이 링크 |            분류            |
| :-----------------------------------------------------------------------: | :------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :-------: | :------------------------: |
| <a href="https://www.acmicpc.net/problem/15685" target="_blank">15685</a> | <a href="https://www.acmicpc.net/problem/15685" target="_blank">드래곤 커브</a> | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> |  [C++]()  | 구현, 시뮬레이션 |
| <a href="https://www.acmicpc.net/problem/1238" target="_blank">1238</a> |     <a href="https://www.acmicpc.net/problem/1238" target="_blank">파티</a>     | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>  |  [C++]()  |             다익스트라             |
|  <a href="https://www.acmicpc.net/problem/2458" target="_blank">2458</a>  |       <a href="https://www.acmicpc.net/problem/2458" target="_blank">키 순서</a>       | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/> |  [C++]()  |             플로이드-워셜             |

### 도전

|                                                 문제 번호                                                  |                                                      문제 이름                                                      |                                       난이도                                       | 풀이 링크 | 분류 |
| :--------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------: | :-------: | :--: |
|                  <a href="https://school.programmers.co.kr/learn/courses/30/lessons/72413" target="_blank">프로그래머스</a>                   |                       <a href="https://school.programmers.co.kr/learn/courses/30/lessons/72413" target="_blank">합승 택시 요금</a>                       | **Lv.3** |  [C++]()  |  플로이드-워셜  |
| <a href="https://www.acmicpc.net/problem/1865" target="_blank">1865</a> | <a href="https://www.acmicpc.net/problem/1865" target="_blank">웜홀</a> |   <img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>             |  [C++]()  |  벨만-포드 |
---

### 힌트

<details>
<summary>드래곤 커브</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;뱀의 머리와 꼬리에 변화가 생기고 있네요! 어떤 자료구조가 필요할까요? 뱀의 현재 위치를 직접 나타내보는 것도 좋을 것 같네요.
</div>
</details>

<details>
<summary>파티</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;이제 어떤 지점을 가기만 하는 게 아니라 오기도 해야 하니 다익스트라 알고리즘을 여러 번 사용해야겠습니다!
</div>
</details>

<details>
<summary>키 순서</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;두 사람 사이의 키 순위를 비교해볼까요? 나와 상대방과의 키 순위를 안다는 것은 내가 상대방과의 키 우열을 알거나 상대방이 나와의 키 우열을 안다는 것과 같습니다.
</div>
</details>

<details>
<summary>합승 택시 요금</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;함께 합승할 수 있는 지점은 총 몇 개인가요? 계산에 고려해야 할 가능한 시작, 도착 지점의 쌍이 어떻게 될까요?
</div>
</details>

<details>
<summary>웜홀</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;시간이 뒤로 갈 수 있다네요? 음수 가중치일때 사용할 수 있는 알고리즘을 배웠었죠! 것보다 벨만 포드는 분명 출발점이 특정한 한 점일때 가능한 알고리즘이라고 배웠는데,시작지점이 정해져있지 않네요. 그런데 특정 정점 하나만 확인하면 해당 정점과 단절된 노드가 포함된 음수 사이클을 발견할 수 없죠! 우리는 최단거리에는 관심이 없고, 오로지 음수 사이클의 존재 여부만 확인하고 싶은 상황에서 어떻게 하면 될까요?
</div>
</details>


---
