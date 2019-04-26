#strict
#appendto TREE

func Initialize() {
  if(GetID()!=BM9Z) return(_inherited());
  while(Var()=FindObject(0,0,0,0,0,OCF_Chop(),0,0,0,Var()))
    if(!Random(2)) SetCategory(32785,Var());
}

private ReproductionAreaSize: return(_inherited()); // Gr��e des Bereichs, in dem neue B�ume dieser Art entstehen k�nnen
private MaxTreeCount:         return(_inherited());  // Maximale Baumanzahl im Umkreis

public Reproduction:
  // Ist noch Platz f�r einen Baum?
  if(ObjectCount(0, Var(1)=(Var(0)=ReproductionAreaSize())/-2, Var(1), Var(0), Var(0), OCF_Chop())<MaxTreeCount())  {
    // OK, hin damit
       Var(2)=PlaceVegetation(GetID(this()), Var(1), Var(1), Var(0), Var(0), 10);
       if(!Random(2)) SetCategory(32785,Var(2));
       return(1);}
  // Kein Platz ;'(
  return(0);
