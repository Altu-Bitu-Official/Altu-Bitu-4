fun main() = with(System.`in`.bufferedReader()){
    val (A,B) = readLine().split(" ").map{it.toInt()}
    val gcd = gcd(A,B)
    println(gcd)
    println(lcm(A,B,gcd))
}
fun gcd(a:Int, b:Int):Int = when(a%b){
    0 -> b
    else ->gcd(b, a%b)
}
fun lcm(a:Int, b:Int, gcd: Int):Int = (a*b)/gcd