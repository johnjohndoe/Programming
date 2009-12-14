//////////////////////////////////////////////////////////////////////////////
// Programming - Übung 3
// Schnittstelle ITrackManager.h
// Tim Wöhrle, 2009-11-24
// 
// 2009-12-07: Ergänzung CTrackInfo::mIndex
//////////////////////////////////////////////////////////////////////////////

#include <string>
using namespace std;

#ifndef ITrackManager_H
#define ITrackManager_H


// MP3-Metadaten. 
struct CTrackInfo
{
   int mIndex;  // 2009-12-07 Ergänzung TW
   string mTitle;
   string mInterpret;
   string mAlbum;
};


// Handle für einen Suchdurchlauf
typedef int TSearchID;

// Konstanten für ungültigen Index bzw. SearchID
#define INVALID_INDEX -1
#define INVALID_SEARCH_ID -1


class ITrackManager
{
public:

   // Liest ein MP3-File ein, legt die Metadaten in der Gesamtliste ab,
   // und liefert die sie zurück
   // param: 
   // return: index, mit dem auf den Track zugegriffen werden kann
   //         INVALID_INDEX, wenn der Track bereits enthalten ist.
   virtual int addTrack( const string pFileName, /*out*/ CTrackInfo &pTrackData ) = 0;

   // Entfernt einen Track mit dem gegebenen Index
   // return: false, wenn der Index nicht enthalten war
   virtual bool removeTrack( int pIndex ) = 0;

   // Startet eine Suche nach den Wortanfängen der Track-Titel. 
   // Es werden noch keine gefundenen Tracks zurückgeliefert, sondern nur die Anzahl der 
   // passenden Tracks, und eine Such-ID.  Mit der Such-ID können anschließend per 
   // trackGetNext() die einzelnen gefundenen Track abgerufen werden. 
   // Mit trackSearchStop() wird die aktuelle Suche beendet.
   virtual int trackSearchStart( const string &pTitleBeginn, /*out*/ TSearchID &pID ) = 0;
   virtual bool trackGetNext( TSearchID pID, /*out*/ CTrackInfo &pNextTrack ) = 0;
   virtual void trackSearchStop( TSearchID pID ) = 0;
};

#endif // ITrackManager_H