import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    while(true) {
        val sentence = readLine()
        if(sentence == ".") break // 입력의 종료조건으로 맨 마지막에 온점 하나(".") 들어옴

        var flag = "yes"
        val stack = Stack<Char>()

        sentence.forEach {
            when(it){
                '(','[' -> stack.push(it)
                ')'->{
                    when(stack.getOrNull(stack.size-1)){
                        '(' -> stack.pop()
                        else -> flag = "no"
                    }
                }
                ']'->{
                    when(stack.getOrNull(stack.size-1)){
                        '[' -> stack.pop()
                        else -> flag = "no"
                    }
                }
            }
        }

        if(stack.isNotEmpty()) flag = "no"

        println(flag)
    }
}
