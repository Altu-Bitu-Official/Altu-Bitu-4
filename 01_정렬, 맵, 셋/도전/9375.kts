fun main(args:Array<String>) = with(System.`in`.bufferedReader()){
    val T = readLine().toInt() // 테스트 케이스 개수

    repeat(T){
        val n = readLine().toInt()
        val clothes = HashMap<String, Int>() // 의상의 종류를 key, 종류의 개수를 value

        repeat(n){
            val type = readLine().split(" ")[1]
            clothes[type] = clothes.getOrElse(type) {0} + 1
        }

        println(clothes.values.fold(1){acc, i -> acc* (i+1) } - 1) // 모든 종류에서 0개를 고른 상황을 제외

    }
}
