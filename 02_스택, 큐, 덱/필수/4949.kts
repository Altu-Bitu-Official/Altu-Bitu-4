import java.util.*

fun main(args:Array<String>) = with(System.`in`.bufferedReader()) {
    while(true) {
        val str = readLine()
        if (str == ".") break

        val stack: Stack<Char> = Stack()

        try {
            str.forEach {
                when(it){
                    '(','[' -> stack.push(it)
                    ')'->{
                        if(stack.peek()=='(')
                            stack.pop()
                        else
                            throw Exception()
                    }
                    ']'->{
                        if(stack.peek()=='[')
                            stack.pop()
                        else
                            throw Exception()
                    }
                }
            }
            if (stack.isEmpty()) println("yes")
            else println("no")
        }
        catch (e: Exception) { println("no") }
    }
}
