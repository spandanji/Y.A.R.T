extern crate bit_vec;
use bit_vec::BitVec;
use std::time::Instant;
use std::io;

fn main(){
    let mut n = String::new();
    io::stdin().read_line(&mut n).expect("Cannot parse input");
    let n:usize = n.trim().parse().expect("Not an integer");
    let t = Instant::now();
    let mut v = BitVec::from_elem(n+1, true);
    v.set(0, false);
    v.set(1, false);
    for i in 2..1+ (n as f64).sqrt() as usize{
        if v[i]{
            let mut j = i*i;
            while j<=n {
                v.set(j, false);
                j+=i;
            }
        }
    }
    let sum = v.iter().enumerate().filter(|(_,x)| *x).fold(0,|sum,(x,_)| sum+x);
    println!("Time :{}ms", t.elapsed().as_millis());
    println!("Sum : {}",sum);
}
