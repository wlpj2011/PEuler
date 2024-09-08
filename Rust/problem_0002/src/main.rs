use std::io;


fn main() {
    loop {
        println!("Please input your Fibonacci number upper bound.");

        let mut upper_bound = String::new();

        io::stdin()
            .read_line(&mut upper_bound)
            .expect("Failed to read line");

        let upper_bound: u32 = match upper_bound.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        let result = fibonacci_sum_even(upper_bound);
        println!("The result is {result}");
        break;
    }
}

fn fibonacci_sum_even(upper_bound: u32) -> u32 {
    let mut sum = 0;
    let mut i = 0;
    loop {
        let current_fib_num = fibonacci(i);
        if current_fib_num > upper_bound {
            break;
        }
        else if current_fib_num % 2 == 0
        {
            sum += current_fib_num;
        }
        i += 1;
    }
    sum
}

fn fibonacci(n : u32) -> u32 {
    //Only works up to 42nd Fibonacci number. i.e. for n ≤ 42.
    if n == 0 {
        return 0;
    }
    else if n == 1 {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}