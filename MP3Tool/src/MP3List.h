#pragma once

class MP3List
{

	// Identifier ist hier nur als Platzhalter zu verstehen f�r das anzusprechende Element. �hnlich
	// einem Iterator. Muss durch interne Mechaniken aufgel�st werden
public:
	MP3List(void);
	insertItem(MP3Data *);
	MP3Data * removeItem(int identifier);
	MP3Data * getItem(int identifier); // F�gt dem Array ein Item hinzu (Schon sortiert?)
	// Wenn ja dann finde die Stelle an der das Teul einzuf�gen ist und tausche von dort zum Ende alle Pointer
	MP3Data * getFirst(void);
	MP3Data * getNext(void); // Wenn 
	int size(void);

	int zaehler; // Zaehlt den aktuellen Z�hlerstand
	void resetZaehler();// Bewirkt ein zur�cksetzen des Zaehlers
	

	~MP3List(void);


private:
	doubleArray(void); // Array wird mit einer default-groesse angelegt. Wenn das Array voll ist dann 
	// verdoppele die groesse und kopiere alle schon vorhandenen Element hinein.
	MP3Data[]* myMp3DataArray; //Speichert Points in ein MP3Data-Array


};
