import kotlin.collections.*

fun main() = with(System.`in`.bufferedReader()){
    val N = readLine().toInt()
    val serialArray = ArrayList<String>()


    repeat(N){
        serialArray.add(readLine())
    }

    serialArray.sortWith(compareBy(
            {it.length},
            {it.filter{s -> s.isDigit()}.sumOf{s->s.digitToInt()}}, // isDigit(): 문자가 숫자이면 true를 반환
            {it}
    ))

    serialArray.forEach{
        println(it)
    }
}