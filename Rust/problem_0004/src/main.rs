use std::io;


fn main() {
    loop {
        println!("Please input your number of digits.");

        let mut num_digits = String::new();

        io::stdin()
            .read_line(&mut num_digits)
            .expect("Failed to read line");

        let num_digits: u32 = match num_digits.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        //let result = mul_3_5_sum(upper_bound);
        //println!("The result is {result}");
        //is_palindrome(num_digits);
        break;
    }
}

fn is_palindrome(number: u32) -> bool {
    let num_digits = ((number as f32) + 0.1).log10().ceil() as u32;
    true 
}

