// Scanner는 스페이스, 엔터, 개행문자를 경계로 값을 인식. 버퍼를 사용하지 않으므로, 키보드의 입력이 되는 즉시 프로그램에 보내짐
// bufferedReader는 줄바꿈만 경계로 인식하며, 데이터 타입이 String으로 고정. 줄바꿈이 나타나면 버퍼에 쌓인 내용을 한번에 프로그램에 전송하므로, 입출력 시간이 단축됨

fun main() = with(System.`in`.bufferedReader()) {
    val (N, M) = readLine().split(" ").map { it.toInt() }
    val S = HashSet<String>() // HashSet: 중복 원소가 허용되지 않음. S에 같은 문자열이 허용되지 않으므로, HashSet 사용
    var cnt = 0

    repeat(N) {
        S.add(readLine())
    }

    repeat(M) {
        if (S.contains(readLine())) cnt++
    }

    println(cnt)
}