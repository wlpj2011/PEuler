use std::io;

fn main() {
    loop {
        println!("Please input your number to factor.");

        let mut number = String::new();

        io::stdin()
            .read_line(&mut number)
            .expect("Failed to read line");

        let number: u32 = match number.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        let number_factors = prime_factors(number);
        let result = number_factors[number_factors.len() - 1];
        println!("The result is {result}");
        break;
    }
}

fn prime_factors(number: u32) -> Vec<u32> {
    let mut factors = Vec::new();

    factors
}

fn is_prime(number: u32) -> bool {
    for i in 2..number {
        if number % i == 0 {
            return false;
        }
    }
    true
}
