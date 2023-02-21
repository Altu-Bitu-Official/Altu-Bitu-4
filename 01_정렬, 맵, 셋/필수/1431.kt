import java.util.*
import kotlin.collections.*

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    val N = nextInt()
    val serialArray = ArrayList<String>()
    for(i in 0 until N){
        serialArray.add(i, next())
    }
    serialArray.sortWith(compareBy(
            {it.length},
            {it.filter{s -> s.isDigit()}.sumOf{s->s.digitToInt()}},
            {it}
    ))
    for(i in serialArray){
        println(i)
    }
}