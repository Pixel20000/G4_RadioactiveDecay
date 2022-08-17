 #include "generator.hh"
//include file
 
 
 MyPrimaryGenerator::MyPrimaryGenerator() //create particle
 {
 }
 

 //destructorul;
  MyPrimaryGenerator::~MyPrimaryGenerator() //delete particle
 {
   delete fParticleGun; 
 }
 

 //basic function
 void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
 {

     fParticleGun = new G4ParticleGun(1); //create 1 primary vertex/event

     //stored particle prop. in table
     G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();

     // ...default particle kinematic...

     //find particle and copy inf about the particle
     G4ParticleDefinition *particle = particleTable->FindParticle("geantino");


     //vectors def. (coordinates)
     G4ThreeVector pos(0.,0.,0.); //position vector- in the center
     G4ThreeVector mom(0.,0.,1.); //z direction - momentum vector


     //special function for particle- set the properties.
     //...
     fParticleGun->SetParticlePosition(pos); //for position(in center)
     fParticleGun->SetParticleMomentumDirection(mom); //for z dir
     fParticleGun->SetParticleMomentum(0.*GeV); //for momentum... in natural units

     //...
     fParticleGun->SetParticleDefinition(particle);

    //for my ion
     G4ParticleDefinition *partic = fParticleGun->GetParticleDefinition();

     if(particle == G4Geantino::Geantino())
     {
         G4int Z = 27;
         G4int A = 62;

         G4double charge = 0.*eplus;
         G4double energy = 0.*keV;

         G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z, A, energy);

         fParticleGun->SetParticleDefinition(ion);
         fParticleGun->SetParticleCharge(charge);
         fParticleGun->SetParticleEnergy(energy);
     }

     fParticleGun->GeneratePrimaryVertex(anEvent);
 }


