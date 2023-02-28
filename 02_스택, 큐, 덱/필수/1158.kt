import java.util.*

fun main(args:Array<String>) = with(System.`in`.bufferedReader()){
    val (N, K) = readLine().split(" ").map{it.toInt()}
    val queue = LinkedList<Int>()

    for(i in 1..N){
        queue.add(i)
    }
    var queueSize = queue.size
    var Josephus = "<"
    var cursor = 1

    while(queueSize>=0){
        val element = queue.poll()
        when(cursor<K){
            true ->{
                queue.add(element)
                cursor++
            }
            else ->{
                queueSize--
                Josephus += element
                cursor = 1

                if(queueSize == 0)
                    break
                Josephus += ", "
            }
        }
    }
    Josephus+=">"
    println(Josephus)
}