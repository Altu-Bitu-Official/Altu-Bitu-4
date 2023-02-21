fun main(): Unit = with(System.`in`.bufferedReader()) {
    val (N, M) = readLine().split(" ").map { it.toInt() }
    val S = HashSet<String>()
    var cnt = 0

    repeat(N) {
        S.add(readLine())
    }

    repeat(M) {
        if (S.contains(readLine())) cnt++
    }

    println(cnt)
}