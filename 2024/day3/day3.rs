//answer: 184122457


use std::fs::read_to_string;
//use lazy_static::lazy_static;
use regex::Regex;

fn main() {

    
    let input = read_to_string("input.txt").unwrap();
    let re = Regex::new("mul\\([0-9]*,[0-9]*\\)").unwrap();
    //let m: Vec<String> = str_strip_numbers(&input);
    let list = str_strip_numbers(&input);
    let pairs = Regex::new("\\d+").unwrap();
    let mut total = 0;
    for op in list{

        

        //let mut iter = re.find_iter(op);
        let iter: Vec<_> = pairs.find_iter(op).map(|m| m.as_str().parse::<i64>().unwrap()).collect();
        total += iter[0]*iter[1];
        println!("{:?}",iter);
        //total += var1 * var2;

    }


    println!("Total: {:?}",total);
    //println!("test");
}

fn str_strip_numbers(s: &str) -> Vec<&str> {
    //println!("{:?}",s);

    let RE = Regex::new("mul\\([0-9]*,[0-9]*\\)").unwrap();
    let mut out : Vec<&str> = Vec::new();
    //println!("{:?}",RE.find_iter(s).unwrap());
    // iterate over all matches
    for i in RE.find_iter(s){
        //println!("{:?}",i.as_str());
        out.push(i.as_str());
    }
    return out;
    //println!("{:?}",RE.find_iter(s).map(|x| x.as_str().parse()));
}