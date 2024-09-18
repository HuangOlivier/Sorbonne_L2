let add (x : int) (y : int) : int = x + y

let op (x:int) = -x

(*
let foo l = 
  match l with 
    | [] -> 3 
    | x::y::z -> x + y;;


let foo l = 
  match l with
    | [x] :: [[x]] -> x > 0
    | _ -> false


let foo l = 
  match l with
    | [[x]] @ [[x]] -> x > 0
    | _ -> false;;

let foo l = 
  match l with
    | [[x]] @ [[y]] -> (x=y) && (x > 0)
    | _ -> false

*)
let foo1 l = 
  match l with
    | [x] :: [[y]] -> (x=y) && (x > 0)
    | _ -> false;;




