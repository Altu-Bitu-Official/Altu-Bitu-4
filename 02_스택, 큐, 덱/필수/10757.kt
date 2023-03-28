fun main() = with(System.`in`.bufferedReader()){
    // BigDecimal 자료형 이용
    println(readLine().split(" ").map{it.toBigDecimal()}.reduce{acc,i -> acc+i})
}