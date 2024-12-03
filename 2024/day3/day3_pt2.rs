//mul\([0-9]*,[0-9]*\)
//Answer: 107862689

use std::fs::read_to_string;
//use lazy_static::lazy_static;
use regex::Regex;

fn main() {

    
    let input = read_to_string("input.txt").unwrap();
    let re = Regex::new("mul\\([0-9]*,[0-9]*\\)").unwrap();
    //let m: Vec<String> = str_strip_numbers(&input);
    let list = find_op(&input);
    let pairs = Regex::new("\\d+").unwrap();
    let mut total = 0;
    let mut ena = true;
    for op in list{

        let substring = &op[0..3];
        //println!("test{:?}",substring);

        match substring{

            "mul"=>
                
                if ena{
                    let iter: Vec<_> = pairs.find_iter(op).map(|m| m.as_str().parse::<i64>().unwrap()).collect();
                    total += iter[0]*iter[1];
                    println!("\tPerforming");
                }else{
                    println!("\tSkipping");
                },
            "do("=> {println!("Enabling");
                ena = true},
            "don"=> {println!("Disabling");
                ena = false},
            _=>continue,

        }
        //let mut iter = re.find_iter(op);
        //let iter: Vec<_> = pairs.find_iter(op).map(|m| m.as_str().parse::<i64>().unwrap()).collect();
        //total += iter[0]*iter[1];
        //println!("{:?}",iter);
        //total += var1 * var2;

    }


    println!("Total: {:?}",total);
    //println!("test");
}

fn find_op(s: &str) -> Vec<&str> {
    //println!("{:?}",s);

    let RE = Regex::new("mul\\([0-9]*,[0-9]*\\)|do\\(\\)|don't\\(\\)").unwrap();
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