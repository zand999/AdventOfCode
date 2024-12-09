use std::fs::read_to_string;
//answer: 1333
struct Tower {
    t_type: char,
    x: i64,
    y: i64,
}

fn main() {

    //let mut base_grid = vec![vec!['.'; line_ln]; line_num];
    //let mut base_grid = vec![vec!['.'; line_ln]; line_num];
    //let mut base_grid = vec![vec!['.',0],0];
    //let mut tower_grid = vec![vec![]];

    let mut tower_grid: Vec<Vec<char>> = Vec::new();

    //let mut tower_grid: Vec<Vec<char>> = Vec::new();

    let mut towers: Vec<Tower> = Vec::new();
    //let mut antinode_grid: Vec<Vec<char>>

    let mut total = 0;

    let mut grid_y = 0;
    for line in read_to_string("input.txt").unwrap().lines() {
        //result.push(line.to_string());
        let mut line_v: Vec<char> = Vec::new();
        
        let mut grid_x = 0;
        for c in line.chars(){
            if c == '\r' || c == '\n'{
                continue;
            }else{
                //print!("{}",c);
                line_v.push(c);
                if c != '.'{
                    let temp_tower = Tower{
                        t_type: c,
                        x: grid_x,
                        y: grid_y
                    };
                    towers.push(temp_tower);
                }
                
            }
            grid_x += 1;
            
        }
        tower_grid.push(line_v);
        grid_y += 1;
        //println!();

    }

    let mut antinode_grid = vec![vec!['.'; tower_grid[0].len()]; tower_grid.len()];

    towers.sort_by_key(|a| a.t_type );

    println!();

    let mut working_tower = Tower{

        t_type : '\0',
        x: 0,
        y: 0
    };


    for i in 0..towers.len(){

        println!("{:?},{:?},{:?}",towers[i].t_type,towers[i].x,towers[i].y);
        /*if towers[i].t_type != working_tower.t_type{
            working_tower.t_type = towers[i].t_type;
        }*/
        let mut j = i + 1;
        while j < towers.len() {
            if towers[j].t_type != towers[i].t_type{
                break;
            }else{

                let x_diff:i64 = (towers[j].x - towers[i].x);
                let y_diff:i64 = (towers[j].y - towers[i].y);
                println!("\t{:?},{:?}",towers[j].x,towers[j].y);

                let mut dead_zone_1_x:i64 = towers[i].x;
                let mut dead_zone_1_y:i64 = towers[i].y ;
                let mut dead_zone_2_x:i64 = towers[j].x ;
                let mut dead_zone_2_y:i64 = towers[j].y ;

                while inBounds((tower_grid[0].len()) as i64, (tower_grid.len()) as i64,dead_zone_1_x,dead_zone_1_y){
                    
                    antinode_grid[dead_zone_1_y as usize][dead_zone_1_x as usize] = '#';
                    dead_zone_1_x -= x_diff;
                    dead_zone_1_y -= y_diff;
                    //tower_grid[dead_zone_1_y as usize][dead_zone_1_x as usize] = '#';
                    
                }
                while inBounds((tower_grid[0].len()) as i64,(tower_grid.len()) as i64,dead_zone_2_x,dead_zone_2_y){
                    //total += 1;
                    antinode_grid[dead_zone_2_y as usize][dead_zone_2_x as usize] = '#';
                    dead_zone_2_x += x_diff;
                    dead_zone_2_y += y_diff;
                    //tower_grid[dead_zone_2_y as usize][dead_zone_2_x as usize] = '$';
                }
                j += 1;
            }
        }

    }

    
    
    //let mut base_grid = vec![vec!['.'; tower_grid[0].len() ]; tower_grid.len()];

    /*for line in base_grid{
        println!("{:?}",line);
    }*/

    for i in 0..antinode_grid.len(){
        for j in 0..antinode_grid[i].len(){
            if antinode_grid[i][j] == '#'{
                total += 1;
            }
        }
    }
    /*
    for line in tower_grid{
        println!("{:?}",line);
    }*/


    println!("Total:{}",total);
    

}


fn inBounds(grid_x: i64, grid_y: i64, x:i64, y:i64) -> bool {
    let out:bool = x >= 0 && y >= 0 && x < grid_x && y < grid_y;
    println!("\t{},{},{}",x,y,out);
    return out
}