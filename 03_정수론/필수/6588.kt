fun main() = with(System.`in`.bufferedReader()){
    var flag = false
    while(true){
        val n = readLine().toInt()
        if(n==0)
            break
        for(i in 2..n/2){
            if(isPrime(i) && isPrime(n-i)){
                println("$n = $i + ${n-i}")
                flag = true
                break
            }
        }
        if(!flag)
            println("Goldbach's conjecture is wrong.")
    }
}
fun isPrime(n : Int): Boolean{
    var i = 2
    while(i*i<=n){
        if(n%i++ == 0) return false
    }
    return true
}