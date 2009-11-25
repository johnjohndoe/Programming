#pragma once

class MP3List
{

	// Identifier ist hier nur als Platzhalter zu verstehen für das anzusprechende Element. Ähnlich
	// einem Iterator. Muss durch interne Mechaniken aufgelöst werden
public:
	MP3List(void);
	insertItem(MP3Data *);
	MP3Data * removeItem(int identifier);
	MP3Data * getItem(int identifier); // Fügt dem Array ein Item hinzu (Schon sortiert?)
	// Wenn ja dann finde die Stelle an der das Teul einzufügen ist und tausche von dort zum Ende alle Pointer
	MP3Data * getFirst(void);
	MP3Data * getNext(void); // Wenn 
	int size(void);

	int zaehler; // Zaehlt den aktuellen Zählerstand
	void resetZaehler();// Bewirkt ein zurücksetzen des Zaehlers
	

	~MP3List(void);


private:
	doubleArray(void); // Array wird mit einer default-groesse angelegt. Wenn das Array voll ist dann 
	// verdoppele die groesse und kopiere alle schon vorhandenen Element hinein.
	MP3Data[]* myMp3DataArray; //Speichert Points in ein MP3Data-Array


};
