import java.rmi.Naming;

public class Servidor {
    public Servidor(){
        try {
            System.out.println("ESTAMOS EN EL SERVIDOR DEL DONATIVOS");
            InterfazRMI objetD = new ImplementationRMI();
            Naming.rebind("rmi://localhost/donativos", objetD);
        } catch (Exception e) {
            //TODO: handle exception
        }
    }
    public static void main(String [] args){
        new Servidor();
    }
}
