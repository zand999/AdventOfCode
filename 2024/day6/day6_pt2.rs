use std::fs::read_to_string;
//answer: 1304


fn main() {

    let input = read_to_string("input.txt").unwrap();
    //println!("{:?}",input);
    //let data = lines.unwrap().chars();
    let line_num = 130;
    let line_ln = 130;
    let mut grid = vec![vec!['.'; line_ln]; line_num];
    //let mut grid = [['#' ; 140] ; 140];
    //println!("{:?}",grid);
    let mut guard_x = 0;
    let mut guard_y = 0;
    
    
    let mut direction = 0;//(NORTH)

    let mut i = 0;
    let mut j = 0;

    let mut total = 0;
    for c in input.chars(){

        if c == '\r' || c == '\n'{
            continue;
        }
        
        if i == line_ln  && j ==  line_num {
            break;
        }else{
            grid[j as usize ][(i%line_ln) as usize] = c; 
            if  grid[j as usize ][(i%line_ln) as usize] == '^'{
                grid[j as usize ][(i%line_ln) as usize] = '.';
                guard_x = i%line_ln;
                guard_y = j;
            }
            //println!("{:?}",c);
            i += 1;
        }

        if i % line_ln ==0 {
            j += 1;
        }
        
    }
    println!("{},{}",guard_x,guard_y);
    let mut old_type = '.';
    
    for i in 0..grid.len(){
        //println!("{}/{}",grid.len(),grid[i].len());
        for j in 0..grid[i].len(){
            
            //println!("{},{}",i,j);
            if (i == guard_x) && (j == guard_y) {
                println!("{},{}",i,j);
                println!("Skipped");
                continue;
                
            }else{
                
                old_type = grid[i][j];
                grid[i][j] = '#';
                //print!("({},{})", i,j);
                if can_be_loop(guard_x,guard_y,grid.to_vec(),false){
                    total += 1;
                    //println!("{}/{}",i,j);
                    //print!("T,");
                    if i ==45 && j == 19{
                        can_be_loop(guard_x,guard_y,grid.to_vec(),true);
                        print!("T,");
                    }
                }
                
                grid[i][j] = old_type;

            }


            
        }
        //println!();
        //println!("{}/{}",i*grid[i].len()+j,grid[i].len()*grid[i].len());
    }
    
    

    

    println!("total: {:?}", total);
    //println!("{:?}",grid);
    //println!("loc{:?}",grid[][]);


}


fn can_be_loop( mut guard_x: usize, mut guard_y: usize, mut grid: Vec<Vec<char>>, debug: bool) -> bool {


    let mut direction = 0;
    //let mut ret_val:bool = false;
    let mut counter = 0;
    while guard_x >= 0 && guard_x < 130 && guard_y >= 0 && guard_y < 130{

        if grid[guard_y][guard_x] == 'X'{
            grid[guard_y][guard_x] = 'Y';
        }else if grid[guard_y][guard_x] == 'Y'{
            grid[guard_y][guard_x] = 'Z';
        }else if grid[guard_y][guard_x] == 'Z'{
            grid[guard_y][guard_x] = 'A';
        }else if grid[guard_y][guard_x] == 'A'{
            if debug{
                for i in 0..grid.len(){
                    for j in 0..grid[i].len(){
                        print!("{}",grid[i][j]);
                        //grid[i][j] = '#';
                    }
                    println!();
                }
                
            }
            return true;
        }else{
            grid[guard_y][guard_x] = 'X';
        }

        //grid[guard_y][guard_x] = 'X';
        //println!("{},{}", guard_y,guard_x);
        if direction == 0{
            if guard_y > 0 && guard_y - 1 >= 0{
                if grid[guard_y - 1][guard_x] == '#'{
                    direction += 1;
                }else{
                    guard_y -= 1;
                }
            }else{
                if (guard_y as i64) - 1  < 0{
                    break;
                }
                guard_y -= 1;
            }
        }
        if direction == 1{
            if guard_x < grid[guard_y].len() - 1 && guard_x + 1 < grid[guard_y].len(){
                if grid[guard_y][guard_x + 1] == '#'{
                    direction += 1;
                }else{
                    guard_x += 1;
                }
            
            }else{
                guard_x += 1;
            }
        }
        if direction == 2{
            if guard_y < grid.len() - 1 && guard_y + 1 < grid.len(){

                if (grid[guard_y + 1][guard_x] == '#'){
                    direction += 1;
                }else{
                    guard_y += 1;
                }
            }else{
                guard_y += 1;
            }
        }
        if direction == 3{
            if guard_x > 0 && guard_x - 1 >= 0{
                if grid[guard_y][guard_x - 1] == '#'{
                    direction = 0;
                }else{
                    guard_x -= 1;
                }
                
            }else{
                if (guard_x as i64) - 1  < 0{
                    break;
                }
                guard_x -= 1;
                
            }
        }

        /*if counter == 1000{
            for i in 0..grid.len(){
                for j in 0..grid[i].len(){
                    print!("{}",grid[i][j]);
                    //grid[i][j] = '#';
                }
                println!();
            }
        }else{
            counter += 1;
        }*/
    }

    if debug{
        for i in 0..grid.len(){
            for j in 0..grid[i].len(){
                print!("{}",grid[i][j]);
                //grid[i][j] = '#';
            }
            println!();
        }

    }
    


    return false;


}

/*
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


*/

/*while guard_x >= 0 && guard_x < 130 && guard_y >= 0 && guard_y < 130{
        grid[guard_y][guard_x] = 'X';
        //println!("{},{}", guard_y,guard_x);
        if direction == 0{
            if guard_y > 0 && guard_y - 1 >= 0{
                if grid[guard_y - 1][guard_x] == '#'{
                    direction += 1;
                }else{
                    guard_y -= 1;
                }
            }else{
                if (guard_y as i64) - 1  < 0{
                    break;
                }
                guard_y -= 1;
            }
        }
        if direction == 1{
            if guard_x < line_ln - 1 && guard_x + 1 < line_ln{
                if grid[guard_y][guard_x + 1] == '#'{
                    direction += 1;
                }else{
                    guard_x += 1;
                }
            
            }else{
                guard_x += 1;
            }
        }
        if direction == 2{
            if guard_y < line_num - 1 && guard_y + 1 < line_num{

                if (grid[guard_y + 1][guard_x] == '#'){
                    direction += 1;
                }else{
                    guard_y += 1;
                }
            }else{
                guard_y += 1;
            }
        }
        if direction == 3{
            if guard_x > 0 && guard_x - 1 >= 0{
                if grid[guard_y][guard_x - 1] == '#'{
                    direction = 0;
                }else{
                    guard_x -= 1;
                }
                
            }else{
                if (guard_x as i64) - 1  < 0{
                    break;
                }
                guard_x -= 1;
                
            }
        }

        //check for loop.
        if can_be_loop(direction,guard_x,guard_y,grid.to_vec()){
            total += 1;
        }
    }*/

    
    /*for i in 0..line_num{
        for j in 0..line_ln{
            print!("{}", grid[i][j].to_string());

        }
        println!();
    }*/