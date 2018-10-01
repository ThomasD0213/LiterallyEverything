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
                System.out.println("What is your issue? 1: Hardware 2: Software 3: Tech Support  ");
                int i = scan.nextInt();

                switch(i){
                    case 1:
                        questions.listToString(questions.getHardwareQuestions());
                        System.out.println("Please choose: 0 - " + (questions.getHardwareQuestions().size() - 1));
                        i = scan.nextInt();
                        System.out.println(questions.getAnswer(1, i));
                        closed = thing();
                        break;
                    case 2:
                        questions.listToString(questions.getSoftwareQuestions());
                        System.out.println("Please choose: 0 - " + (questions.getSoftwareQuestions().size() - 1));
                        i = scan.nextInt();
                        System.out.println(questions.getAnswer(2, i));
                        closed = thing();
                        break;
                    case 3:
                        questions.listToString(questions.getTechSuppQuestions());
                        System.out.println("Please choose: 0 - " + (questions.getTechSuppQuestions().size() - 1));
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
            System.out.println("Did that solve your issue? (Y/N): ");
            String thing = scan.nextLine();
            if(thing.toLowerCase().equals("y"))
            {
                System.out.println("Thank you for using our HelpDesk, have a great day!!");
                return true;
            }
            else
                {
                    return false;
                }

        }
    }   