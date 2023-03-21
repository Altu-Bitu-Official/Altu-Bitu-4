import java.util.*
import kotlin.collections.*

fun main() = with(System.`in`.bufferedReader()){
    val (N,K) = readLine().split(" ").map{it.toInt()}
    val wheel = LinkedList(Collections.nCopies(N,'?'))
    val stack = Stack<Char>()

    repeat(K){
        val (m, alphabet) = readLine().split(" ")
        stack.addAll(Collections.nCopies(m.toInt()-1,'?'))
        stack.push(alphabet[0])
    }

    var i = 0
    while(stack.isNotEmpty()){
        val p = stack.pop()
        if(p != '?'){
            when(wheel[i]){
                p -> {}
                '?' -> {
                    // 바퀴에 같은 글자가 2번 이상 등장한 경우
                    if(Collections.frequency(wheel,p)>0){
                        wheel.clear()
                        wheel.add('!')
                        break
                    }
                    else
                        wheel[i] = p
                }
                // 바퀴 인덱스에 이미 다른 값이 저장된 경우
                else -> {
                    wheel.clear()
                    wheel.add('!')
                    break
                }
            }
        }
        i = (i+1)%N
    }

    wheel.forEach {
        print(it)
    }
}