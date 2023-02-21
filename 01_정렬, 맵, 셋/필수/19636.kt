import java.util.*
import kotlin.math.*

private  lateinit var STR : String
fun main(args: Array<String>) = with(Scanner(System.`in`)){
    val W0 = nextInt()
    val L0 = nextInt()
    val A0 = 0
    val T = nextInt()
    val D = nextInt()
    val L = nextInt()
    val A = nextInt()

    var k = L0
    var W1  = W0
    var W2  = W0

    for(i in 1..D){
        W1 += (L-L0-A)
        W2 += (L-k-A)
        if(abs((L-k-A))>T)
            k += floor((L - k - A)/ 2.0).toInt()
        when{
            W1<=0||W2<=0||k<=0 -> STR = "Danger Diet"
            else -> continue
        }
    }
    when(W1<=0){
        true -> println(STR)
        else -> println("$W1 $L0")
    }
    when{
        W2<=0 || k<=0 -> println(STR)
        else -> {
            STR = when(L0 - (k + A0)>0){
                true -> "YOYO"
                else -> "NO"
            }
            println("$W2 $k $STR")
        }
    }
}