import java.util.*

fun main() = with(System.`in`.bufferedReader()){
    val (N, K) = readLine().split(" ").map{it.toInt()}
    val queue = LinkedList<Int>() // queue 구현

    for(i in 1..N){
        queue.add(i) // 1 ~ N 순으로 queue에 입력
    }
    var queueSize = queue.size
    var Josephus = "<"
    var cursor = 1

    while(queueSize>=0){
        val element = queue.poll() // head의 element
        when(cursor<K){
            true ->{
                queue.add(element) // queue의 끝에 붙임
                cursor++
            }
            else ->{
                queueSize-- // queue의 끝에 붙이지 않음
                Josephus += element
                cursor = 1

                when(queueSize){  // 모든 원소를 Josephus에 추가할 때까지 반복
                    0 -> {
                        Josephus+=">"
                        break
                    }
                    else -> Josephus += ", "
                }
            }
        }
    }

    println(Josephus)
}