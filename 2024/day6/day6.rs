use std::fs::read_to_string;
//answer: 4789


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
                guard_x = i%line_ln;//changed without compiling
                guard_y = j;//changed without compiling
            }
            println!("{:?}",c);
            i += 1;
        }

        if i % line_ln ==0 {
            j += 1;
        }
        
    }

    while guard_x >= 0 && guard_x < 130 && guard_y >= 0 && guard_y < 130{
        grid[guard_y][guard_x] = 'X';
        println!("{},{}", guard_y,guard_x);
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
                print!("here1");
                guard_x -= 1;
                print!("here2");
                
            }
        }

    }

    for i in 0..line_num{
        for j in 0..line_ln{
            if grid[i][j] == 'X'{
                total += 1;
            }
            print!("{}", grid[i][j].to_string());

        }
        println!();
    }

    

    println!("total: {:?}", total);
    //println!("{:?}",grid);
    //println!("loc{:?}",grid[][]);


}