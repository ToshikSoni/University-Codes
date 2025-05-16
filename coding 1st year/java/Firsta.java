class Firsta {
    public static void main(String args[]) {
        int n;
        n = args.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (args[i].equalsIgnoreCase(args[j]) && i != j) {
                    System.out.println("Argument " + i + " " + j + " are equal.");
                }
            }
        }
    }
}