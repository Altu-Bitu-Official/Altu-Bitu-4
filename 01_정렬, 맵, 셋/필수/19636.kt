import java.util.*
import kotlin.math.*

private  lateinit var STR : String
fun main(args: Array<String>) = with(Scanner(System.`in`)){
    val W0 = nextInt() // 원래 체중
    val L0 = nextInt() // 원래 일일 에너지 섭취량, 원래 일일 기초 대사량
    val A0 = 0 // 원래 일일 활동 대사량
    val T = nextInt() // 기초 대사량 변화 역치
    val D = nextInt() // 다이어트 일수
    val L = nextInt() // 다이어트 기간의 일일 에너지 섭취량
    val A = nextInt() // 다이어트 기간의 일일 활동 대사량

    var k = L0 // 다이어트 기간의 일일 기초 대사량
    var W1  = W0 // 일일 기초 대사량의 변화를 고려하지 않은 최종 체중
    var W2  = W0 // 일일 기초 대사량의 변화를 고려한 최종 체중

    repeat(D){
        W1 += (L-L0-A)
        W2 += (L-k-A)
        if(abs((L-k-A))>T)
            k += floor((L - k - A)/ 2.0).toInt()
        if(W1<=0||W2<=0||k<=0)
            STR = "Danger Diet"
    }
    // 첫번째 줄 출력
    when(W1<=0){
        true -> println(STR)
        else -> println("$W1 $L0")
    }
    // 두번째 줄 출력
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