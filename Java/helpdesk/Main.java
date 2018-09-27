import java.util.Scanner;

public class Main
    {
         //dunno what to name this as, 2d array of help desks

        public static void main(String[] args)
        {
            HelpDesk questions = new HelpDesk();
            boolean closed = false;
            Scanner scan = new Scanner(System.in);
            while(!closed)
            {
                System.out.print("What is your issue? 1: Hardware 2: Software 3: other  ");
                int i = scan.nextInt();

                switch(i){
                    case 1:
                        System.out.println(questions.getHardwareQuestions());
                        System.out.print("What is your question? ");
                        i = scan.nextInt();
                        System.out.println(questions.getAnswer(1, i));
                        closed = thing();
                        break;
                    case 2:
                        System.out.println(questions.getSoftwareQuestions());
                        System.out.print("What is your question? ");
                        i = scan.nextInt();
                        System.out.println(questions.getAnswer(2, i));
                        closed = thing();
                        break;
                    case 3:
                        System.out.println(questions.getTechSuppQuestions());
                        System.out.print("What is your question? ");
                        i = scan.nextInt();
                        System.out.println(questions.getAnswer(3, i));
                        closed = thing();
                        break;
                    default:
                        System.out.println("not a valid option!");
                }
            }


        }
        private static boolean thing()
        {
            Scanner scan = new Scanner(System.in);
            System.out.print("Did that solve your issue? (Y/N): ");
            String thing = scan.nextLine();
            if(thing.toLowerCase().equals("y"))
            {
                System.out.println("Have a nice day!");
                return true;
            }
            else
                {
                    return false;
                }

        }
    }   