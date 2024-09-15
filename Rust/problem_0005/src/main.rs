use std::io;

fn main() {
    loop {
        println!("Please input the largest number as part of the lcm.");

        let mut number = String::new();

        io::stdin()
            .read_line(&mut number)
            .expect("Failed to read line");

        let number: u32 = match number.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        let result = lcm_up_to(number);
        println!("The result is {result}");
        break;
    }
}

fn lcm_up_to(number: u32) -> u32 {
    euclidean_algorithm(number, number - 1)
}

fn euclidean_algorithm(number1: u32, number2: u32) -> u32 {
    number1
}
