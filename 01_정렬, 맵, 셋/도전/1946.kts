import kotlin.collections.*

fun main(args:Array<String>) = with(System.`in`.bufferedReader()){
    val T = readLine().toInt() // 테스트 케이스 개수

    repeat(T){
        val N = readLine().toInt() // 지원자 수
        val score = ArrayList<Pair<Int,Int>>() // 지원자 순위

        repeat(N){
            val (r1, r2) = readLine().split(" ").map{it.toInt()}
            score.add(Pair(r1,r2))
        }

        // 서류심사 순위가 높은 순으로 정렬
        score.sortBy{it.first}

        var cnt = 1 // 서류심사 1등은 무조건 합격
        var currentHighRanking = score[0].second // 지금까지의 순회중 가장 높은 순위

        for(s in score - score[0]){
            if(currentHighRanking>s.second) {
                cnt++
                currentHighRanking = s.second // 가장 높은 순위 update
            }
        }

        println(cnt)
    }
}