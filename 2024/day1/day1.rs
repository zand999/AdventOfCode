
use std::fs::read_to_string;

fn main() {

    let mut list1 : Vec<i64> = Vec::new();
    let mut list2 : Vec<i64> = Vec::new();

    for line in read_to_string("input.txt").unwrap().lines() {
        //result.push(line.to_string());
        let line = line.to_string();
        let mut split = line.split("   ");
        //println!("{l1}");
        
        //let var1 = split.next().unwrap().parse::<i64>().unwrap();
        //let var2 = split.next().unwrap().parse::<i64>().unwrap();


        //println!("{:?},{:?}",var1,var2);

        list1.push(split.next().unwrap().parse::<i64>().unwrap());
        list2.push(split.next().unwrap().parse::<i64>().unwrap());


    }

    list1.sort();
    list2.sort();

    let mut answer1 = 0;
    let mut answer2 = 0;

    for i in 0..(list1.len()){

        
        let difference = list1[i] - list2[i];
        answer1 += difference.abs();
        //let mut count = list2.iter().filter(list1[i]).count();
        /*let mut count = 0;
        for j in 0..(list2.len()){
            if list2[j] == list1[i]{
                count += 1;
            }

        }*/
        let mut count = 0;
        for num in list2.iter(){

            if *num == list1[i]{
                count += 1;
            }
        }

        answer2 += list1[i] * count;

    }

    println!("Answer1: {answer1}");
    println!("Answer2: {answer2}");

}