fun main() = with(System.`in`.bufferedReader()){
    val N = readLine().toInt()
    val num = readLine().split(" ").map { it.toInt() }

    for(M in num) {
        var m = M
        val twoToN = ArrayList<Int>()
        when(isPrime(m)){
            true ->println(m)
            else -> {
                for(i in 2..m){
                    if(isPrime(i)) twoToN.add(i)
                }
                var i = 0
                while(true) {
                    if (m % num[i] == 0) {
                        print("$num[i]  ")
                        m /= num[i]
                        if (m == 1) {
                            print("\n")
                            break
                        } else{
                            i=2
                        }
                    } else{
                        i++
                    }
                }
            }
        }
    }
}
fun isPrime(n : Int): Boolean{
    var i = 2
    while(i*i <= n){
        if(n%i++==0) return false
    }
    return true
}