use std::fs::read_to_string;

//answer: 398


fn main() {

    //let mut list1 : Vec<i64> = Vec::new();
    //let mut list2 : Vec<i64> = Vec::new();
    let mut total_good = 0;
    for line in read_to_string("input.txt").unwrap().lines() {
        //result.push(line.to_string());
        let line = line.to_string();
        let mut split = line.split(" ");
        let mut list : Vec<i64> = Vec::new();

        for val in split{
            list.push(val.parse::<i64>().unwrap());
        }

        //println!("{:?}",list);
        //let isGood:bool = false;
        for i in 0..list.len(){
            let mut shortenedlist = list.to_vec();
            shortenedlist.remove(i);
            
            if (isGood(&mut shortenedlist)) {
                total_good += 1;
                break;
            }


        }

       
    }

    println!("Total good: {total_good}");

    
}

fn isGood(list: &mut Vec<i64>) -> bool{

    
    let mut mode = 0;

    if list[0] > list[1]{
        mode = 1;
    }


    for i in 0..list.len()-1{

    

        if mode == 0 {
            if list[i] > list[i+1] || list[i+1] - list[i] > 3 || list[i+1] - list[i] < 1 || list[i+1] == list[i]{
                return false;
            }
        }else if mode == 1{
            if list[i] < list[i+1] || list[i] - list[i+1]  < 1 || list[i] - list[i+1]  > 3 || list[i+1] == list[i]{
                return false;
            }
        }

    }

    return true;
    
}