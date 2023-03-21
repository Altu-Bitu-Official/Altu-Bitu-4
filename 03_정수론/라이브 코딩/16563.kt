import java.util.*

fun main(args: Array<String>) = with(System.`in`.bufferedReader()){
    val sb = StringBuilder()
    val N = readLine().toInt() // 자연수 개수

    val minFactor = IntArray(5000001)
    for (i in 2..5000000) {
        minFactor[i] = i
    }

    // 미리 각 자연수의 가장 작은 소인수를 저장해 둔다.
    var i = 2
    while (i * i <= 5000000) {
        if (minFactor[i] == i) {    // i가 소수라면
            var j = i * i
            while (j <= 5000000) {
                // 그 다음 큰 배수부터 전부 해당 소수로 표시 (각 자연수의 가장 작은 소인수 값이 저장됨)
                if (minFactor[j] == j) {
                    minFactor[j] = i
                }
                j += i
            }
        }
        i++
    }
    val st = StringTokenizer(readLine())
    for (i in 0 until N) {
        var n = st.nextToken().toInt()

        // 소인수 분해
        while (n > 1) {
            sb.append(minFactor[n].toString() + " ")
            n /= minFactor[n]
        }
        sb.append("\n")
    }
    println(sb.toString())
}