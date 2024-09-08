use std::io;


fn main() {
    loop {
        println!("Please input your loop upper bound.");

        let mut upper_bound = String::new();

        io::stdin()
            .read_line(&mut upper_bound)
            .expect("Failed to read line");

        let upper_bound: u32 = match upper_bound.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        let result = mul_3_5_sum(upper_bound);
        println!("The result is {result}");
        break;
    }
}

fn mul_3_5_sum(upper_bound: u32) -> u32 {
    let mut sum = 0;
    for number in 1..upper_bound {
        if (number % 3 == 0) || (number % 5 == 0) {
            sum += number;
        }
    }
    sum
}
