import java.util.*

fun main() = with(System.`in`.bufferedReader()){
    var (N,K) = readLine().split(" ").map{it.toInt()}
    val queue = LinkedList<Int>()

    for(i in 2..N){
        queue.add(i)
    }

    while(K>0){
        val P = queue.poll()
        K--
        if(K==0) println(P)

        repeat(queue.size){
            val element = queue.poll()
            when(element%P){
                0-> {
                    K--
                    if(K==0) {
                        println(element)
                        return@with
                    }
                }
                else -> queue.add(element)
            }
        }
        }
    }
