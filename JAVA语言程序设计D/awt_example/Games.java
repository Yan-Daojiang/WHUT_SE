class Game {
 protected void play(){
  System.out.println("play game");
 }
}


 class Football extends Game {
 protected void play() {
    System.out.println("play football");
    super.play();
 }
 void f(){
  play();
 }
}



 class Basketball extends Game{
 protected void play() {
  System.out.println("play basketball");
 }
}


 class Popolong extends Game {
 protected void play() {
  System.out.println("play popolong");
 }

}



public class Games {

 public static void main(String[] args) {
  Game[] games = new Game[10];
  games[0] = new Basketball();
  games[1] = new Football();
  games[2] = new Popolong();
  
  for(int i=0;i<games.length;i++){
   if(games[i]!=null)
      games[i].play();
  }
  
 }

}
