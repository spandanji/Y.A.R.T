use std::io;
use std::time::Instant;

fn main() {
    let mut n = String::new();
    io::stdin()
        .read_line(&mut n)
        .expect("Failed to parse input");
    let n: usize = n.trim().parse().expect("Not a number");
    let t = Instant::now();
    let mut sum: usize = 0;
    let mut primes = vec![1 as u8; n + 1];
    primes[1] = 1u8;

    for i in 2..(((n as f32).sqrt().floor() as usize)+1) {
        if primes[i]==1u8{
            let mut j = i*i;
            while j<=n {
                primes[j] = 0u8;
                j+=i;
            }
        }
    }

    //println!("Time : {}", t.elapsed().as_millis());
    for (i, j) in primes.iter().enumerate().skip(2){
        if *j == 1u8 {
            sum += i;
        }
    }

    println!("Time : {}ms", t.elapsed().as_millis());
    println!("Sum : {}", sum);
}
