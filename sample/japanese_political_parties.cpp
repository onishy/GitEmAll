#include <iostream>
#include "git_tree.hpp"

/* Example for creating a tree of Japanese Political Parties */

int main() {
    GitEmAll::Branch Origin;

    auto NihonJiyuTo = Origin.fork(194501, "NihonJiyuTo", "日本自由党結党");
    auto MinshuJiyuTo = NihonJiyuTo.fork(194801, "MinshuJiyuTo", "民主自由党が日本自由党から分党");
    auto JiyuTo50 = MinshuJiyuTo.fork(195001, "JiyuTo50", "自由党が民主自由党から分党");
    auto JiyuMinshuTo = JiyuTo50.fork(195501, "JiyuMinshuTo", "自由党が自由民主党へ参加");
    auto ShinJiyuTo = NihonJiyuTo.fork(194802, "ShinJiyuTo", "新自由党が日本自由党から分党");
    MinshuJiyuTo.merge(194901, ShinJiyuTo, "新自由党が民主自由党へ合流");
    auto BuntouhaJiyuTo = JiyuTo50.fork(195301, "BuntouhaJiyuTo", "分党派自由党が自由党から分裂");
    NihonJiyuTo.merge(195302, BuntouhaJiyuTo, "分党派自由党が日本自由党に合流");

    auto NihonShimpoTo = Origin.fork(194502, "NihonShimpoTo", "日本進歩党結党");
    auto MinshuTo47 = NihonShimpoTo.fork(194701, "MinshuTo47", "日本進歩党が民主党へ改名");
    auto KokuminMinshuTo = MinshuTo47.fork(195001, "KokuminMinshuTo", "民主党が国民民主党へ合流");
    auto KaishinTo = KokuminMinshuTo.fork(195201, "KaishinTo", "国民民主党が改進党へ合流");
    auto NihonMinshuTo = KaishinTo.fork(195401, "NihonMinshuTo", "改進党から日本民主党結党");
    NihonMinshuTo.merge(195402, NihonJiyuTo, "日本自由党が日本民主党へ参加");
    JiyuMinshuTo.merge(195502, NihonMinshuTo, "日本民主党が自由民主党へ参加");

    auto NihonKyoudouTo = Origin.fork(194501, "NihonKyoudouTo", "日本協同党結党");
    auto KyoudouMinshuTo = NihonKyoudouTo.fork(194601, "KyoudouMinshuTo", "協同民主党が日本協同党から参加");
    auto KokuminKyoudouTo = KyoudouMinshuTo.fork(194702, "KokuminKyoudouTo", "国民協同党が協同民主党から参加");
    KokuminMinshuTo.merge(195202, KokuminKyoudouTo, "国民協同党が国民民主党に合流");

    auto KokuminTo = Origin.fork(194601, "KokuminTo", "国民党結党");
    KokuminKyoudouTo.merge(194703, KokuminTo, "国民党が国民協同党に合流");

    auto NihonNouminTo = Origin.fork(194701, "NihonNouminTo", "日本農民党が結党");
    auto NouminShinTo = NihonNouminTo.fork(194801, "NouminShinTo", "農民新党が日本農民党から分裂");
    auto NouminKyoudouTo = NouminShinTo.fork(194901, "NouminKyoudouTo", "農民新党が農民協同党に参加");
    NouminKyoudouTo.merge(194902, NihonNouminTo, "日本農民党が農民協同党へ参加");

    auto ShinseiClub = Origin.fork(195101, "ShinseiClub", "新政クラブ結党");
    auto NihonSaikenRenmei = Origin.fork(195201, "NihonSaikenRenmei", "日本再建連盟結党");

    auto NihonKyousanTo = Origin.fork(194501, "NihonKyousanTo", "日本共産党結党");

    auto NihonShakaiTo = Origin.fork(194501, "NihonShakaiTo", "日本社会党結党");
    auto ShakaiKakushinTo = NihonShakaiTo.fork(194701, "ShakaiKakushinTo", "社会革新党が日本社会党から分裂");
    auto ShakaiMinshuTo51 = ShakaiKakushinTo.fork(195101, "ShakaiMinshuTo51", "社会革新党が社会民主党に参加");
    auto KyoudouTo = ShakaiMinshuTo51.fork(195201, "KyoudouTo", "社会民主党が協同党に参加");
    KyoudouTo.merge(195202, NouminKyoudouTo, "農民協同党が協同党に参加");

    auto RoudoushaNouminTo = NihonShakaiTo.fork(194801, "RoudoushaNouminTo", "労働者農民党が日本社会党から分裂");
    NihonShakaiTo.merge(195701, RoudoushaNouminTo, "労働者農民党が日本社会党へ合流");

    auto SahaShakaiTo = NihonShakaiTo.fork(195101, "SahaShakaiTo", "日本社会党から左派社会党が分裂");
    auto UhaShakaiTo = NihonShakaiTo.fork(195101, "UhaShakaiTo", "日本社会党から右派社会党が分裂");
    UhaShakaiTo.merge(195203, KyoudouTo, "協同党が右派社会党に合流");
    NihonShakaiTo.merge(195501, SahaShakaiTo, "左派社会党が日本社会党へ参加");
    NihonShakaiTo.merge(195502, UhaShakaiTo, "右派社会党が日本社会党へ参加");

    auto ShakaiToSaikenZenkokuRenrakukai = NihonShakaiTo.fork(195201, "ShakaiToSaikenZenkokuRenrakukai", "社会党再建全国連絡会が日本社会党から分裂");
    SahaShakaiTo.merge(195500, ShakaiToSaikenZenkokuRenrakukai, "社会党再建全国連絡会が左派社会党に合流");

    auto OkinawaJinminTo = Origin.fork(194701, "OkinawaJinminTo", "沖縄人民党結党");
    NihonKyousanTo.merge(197301, OkinawaJinminTo, "沖縄人民党が日本共産党へ合流");
    auto NihonNoKoe = NihonKyousanTo.fork(196401, "NihonNoKoe", "日本共産党（日本のこえ）が日本共産党から分裂");

    auto MinshuShakaiTo = NihonShakaiTo.fork(196001, "MinshuShakaiTo", "民主社会党が日本社会党から分裂");
    auto MinshaTo = MinshuShakaiTo.fork(196901, "MinshaTo", "民社党が日本社会党から分裂");
    auto ShakaiShiminRengo = NihonShakaiTo.fork(197701, "ShakaiShiminRengo", "社会市民連合が日本社会党より分裂");
    auto ShakaiMinshuRengo = ShakaiShiminRengo.fork(197801, "ShakaiMinshuRengo", "社会民主連合が社会市民連合より分裂");
    auto ShakaiClub = NihonShakaiTo.fork(197701, "ShakaiClub", "社会クラブが日本社会党より分裂");
    ShakaiMinshuRengo.merge(197802, ShakaiClub, "社会クラブが社会民主連合へ参加");

    auto KakushinJiyuMinshuTo = JiyuMinshuTo.fork(195801, "KakushinJiyuMinshuTo", "革新自由民主党が自由民主党より分裂");
    auto ShinJiyuClub = JiyuMinshuTo.fork(197601, "ShinJiyuClub", "新自由クラブが自由民主党より分裂");
    auto ZeikinTo = ShinJiyuClub.fork(198301, "ZeikinTo", "税金等が新自由クラブから分裂");
    auto ShimpoTo = ShinJiyuClub.fork(198701, "ShimpoTo", "進歩党が新自由クラブから分裂");
    JiyuMinshuTo.merge(198702, ShinJiyuClub, "新自由クラブが自由民主党へ合流");

    auto KomeiTo = Origin.fork(196401, "KomeiTo", "公明党結党");

    auto ShakaiMinshuTo96 = NihonShakaiTo.fork(199601, "ShakaiMinshuTo96", "社会民主党が日本社会党より改名");
    auto ShinToGokenLiberal = NihonShakaiTo.fork(199602, "ShinToGokenLiberal", "新党護憲リベラルが日本社会党より分裂");
    auto ShiminLeague = NihonShakaiTo.fork(199603, "ShiminLeague", "市民リーグが日本社会党より分裂");

    auto ShinToSakigake = JiyuMinshuTo.fork(199301, "ShinToSakigake", "新党さきがけが自由民主党より分裂");
    auto Sakigake = ShinToSakigake.fork(199801, "Sakigake", "さきがけが新党さきがけから改名");
    auto MidorinoKaigi = Sakigake.fork(200201, "MidorinoKaigi", "みどりの会議がさきがけより改名");

    auto ShinseiTo = JiyuMinshuTo.fork(199301, "ShinseiTo", "新生党が自由民主党より分裂");
    auto JiyuTo94 = JiyuMinshuTo.fork(199401, "JiyuTo94", "自由党が自由民主党から分裂");
    auto ShinToMirai = JiyuMinshuTo.fork(199401, "ShinToMirai", "新党みらいが自由民主党から分裂");
    auto KoushiKai = JiyuMinshuTo.fork(199401, "KoushiKai", "高志会が自由民主党から分裂");

    auto KomeiShinTo = KomeiTo.fork(199401, "KomeiShinTo", "公明新党が公明党から分裂");
    auto Komei = KomeiTo.fork(199401, "Komei", "公明が公明党から分裂");

    auto NihonShinTo = Origin.fork(199201, "NihonShinTo", "日本新党結党");
    NihonShinTo.merge(199401, ShakaiMinshuRengo, "社会民主連合が日本新党へ合流");
    auto MinshuKaikakuRengo = Origin.fork(199401, "MinshuKaikakuRengo", "民主改革連合結党");

    auto ShinshinTo = Origin.fork(199401, "ShinshinTo", "新進党結党");
    ShinshinTo.merge(199402, ShinseiTo, "新生党が新進党へ参加");
    ShinshinTo.merge(199402, JiyuTo94, "自由党が新進党へ参加");
    ShinshinTo.merge(199402, ShinToMirai, "新党みらいが新進党へ参加");
    ShinshinTo.merge(199402, KoushiKai, "高志会が新進党へ参加");
    ShinshinTo.merge(199402, MinshaTo, "民社党が新進党へ参加");
    ShinshinTo.merge(199402, KomeiShinTo, "公明新党が新進党へ参加");
    ShinshinTo.merge(199402, NihonShinTo, "日本新党が新進党へ参加");

    auto TaiyouTo = ShinshinTo.fork(199801, "TaiyouTo", "太陽党が新進党から分裂");
    auto FromFive = ShinshinTo.fork(199801, "FromFive", "フロム・ファイブが新進党から分裂");
    auto KokuminNoKoe = ShinshinTo.fork(199801, "KokuminNoKoe", "国民の声が新進党から分裂");
    auto ShinToYuai = ShinshinTo.fork(199801, "ShinToYuai", "新党友愛が新進党から分裂");
    auto JiyuTo98 = ShinshinTo.fork(199801, "JiyuTo98", "自由党が新進党から分裂");
    auto HoshuTo = JiyuTo98.fork(200001, "HoshuTo", "保守党が自由党より分裂");
    auto HoshuShinTo = HoshuTo.fork(200201, "HoshuShinTo", "保守新党が保守党より分裂");
    JiyuMinshuTo.merge(200301, HoshuShinTo, "保守新党が自由民主党に合流");

    auto KaikakuClub98 = ShinshinTo.fork(199801, "KaikakuClub98", "改革クラブが新進党から分裂");
    auto ReimeiClub = ShinshinTo.fork(199801, "ReimeiClub", "黎明クラブが新進党から分裂");

    auto MinshuTo96 = Origin.fork(199601, "MinshuTo96", "民主党結党");
    MinshuTo96.merge(199801, MinshuKaikakuRengo, "民主改革連合が民主党へ参加");
    MinshuTo96.merge(199802, ShinToYuai, "新党友愛が民主党へ参加");
    MinshuTo96.merge(200301, JiyuTo98, "自由党が民主党へ合流");

    auto MinseiTo = Origin.fork(199801, "MinseiTo", "民政党結党");
    MinseiTo.merge(199802, TaiyouTo, "太陽党が民政党へ参加");
    MinseiTo.merge(199802, FromFive, "フロム・ファイブが民政党へ参加");
    MinseiTo.merge(199802, KokuminNoKoe, "国民の声が民政党へ参加");

    MinshuTo96.merge(199803, MinseiTo, "民政党が民主党へ参加");

    auto KokuminShinTo = JiyuMinshuTo.fork(200501, "KokuminShinTo", "国民新党が自由民主党から分裂");
    auto ShinToNippon = JiyuMinshuTo.fork(200501, "ShinToNippon", "新党日本が自由民主党から分裂");
    auto TachiagareNippon = JiyuMinshuTo.fork(201001, "TachiagareNippon", "たちあがれ日本が自由民主党から分裂");
    auto TaiyouNoTo12 = TachiagareNippon.fork(201201, "TaiyouNoTo12", "太陽の党がたちあがれ日本から改名");

    auto KaikakuClub08 = MinshuTo96.fork(200801, "KaikakuClub08", "改革クラブが民主党から分裂");
    auto ShinToKaikaku = KaikakuClub08.fork(201001, "ShinToKaikaku", "新党改革が改革クラブから改名");
    auto DaichiShinMinshuTo = MinshuTo96.fork(201101, "DaichiShinMinshuTo", "大地・真民主党が民主党から分裂");
    auto ShinToDaichiShinMinshu = DaichiShinMinshuTo.fork(201201, "ShinToDaichiShinMinshu", "新党大地・真民主が大地・真民主党より改名");
    auto ShinToKizuna = MinshuTo96.fork(201101, "ShinToKizuna", "新党きづなが民主党より分裂");
    auto KokuminNoSeikatsuGaDaiichi = MinshuTo96.fork(201201, "KokuminNoSeikatsuGaDaiichi", "国民の生活が第一が民主党より分裂");
    KokuminNoSeikatsuGaDaiichi.merge(201202, ShinToKizuna, "新党きづなが国民の生活が第一へ合流");

    auto ShinToDaichi = Origin.fork(200501, "ShinToDaichi", "新党大地が結党");
    ShinToDaichi.merge(201202, ShinToDaichiShinMinshu, "新党大地が新党大地・真民主から移管");

    auto MinnaNoTo = Origin.fork(200901, "MinnaNoTo", "みんなの党結党");
    auto NipponWoGenkiNiSuruKai = MinnaNoTo.fork(201501, "NipponWoGenkiNiSuruKai", "日本を元気にする会結党");
    auto YuiNoTo = MinnaNoTo.fork(201301, "YuiNoTo", "結いの党がみんなの党から分裂");

    auto NipponSoushinTo = Origin.fork(201001, "NipponSoushinTo", "日本創新党結党");
    auto GenzeiNippon = Origin.fork(201001, "GenzeiNippon", "減税日本結党");
    auto NipponIshinNoKai = Origin.fork(201201, "NipponIshinNoKai", "日本維新の会結党");
    NipponIshinNoKai.merge(201202, TaiyouNoTo12, "太陽の党が日本維新の会へ合流");
    NipponIshinNoKai.merge(201202, NipponSoushinTo, "日本創新党が日本維新の会へ合流");
    auto IshinNoTo = NipponIshinNoKai.fork(201401, "IshinNoTo", "維新の党が日本維新の会から改名");
    IshinNoTo.merge(201405, YuiNoTo, "結いの党が維新の党へ参加");
    auto JisedaiNoTo = NipponIshinNoKai.fork(201401, "JisedaiNoTo", "次世代の党が日本維新の会から分裂");
    auto NihonNoKokoroWoTaisetsuNiSuruTo = JisedaiNoTo.fork(201501, "NihonNoKokoroWoTaisetsuNiSuruTo", "日本のこころを大切にする党が次世代の党から改名");
    auto OsakaIshinNoKai = IshinNoTo.fork(201502, "OsakaIshinNoKai", "おおさか維新の会が維新の党から分裂");
    auto KaikakuKesshuNoKai = IshinNoTo.fork(201502, "KaikakuKesshuNoKai", "改革結集の会が維新の党から分裂");

    auto MinshinTo = MinshuTo96.fork(201601, "MinshinTo", "民進党が民主党から改名");
    MinshinTo.merge(201602, IshinNoTo, "維新の党が民進党に参加");    
    MinshinTo.merge(201602, KaikakuKesshuNoKai, "改革結集の会が民進党へ参加");

    auto HanTPPDatsugenpatsuShouhizouzeitouketsuWoJitsugenSuruTo = Origin.fork(201201, "HanTPPDatsugenpatsuShouhizouzeitouketsuWoJitsugenSuruTo", "反TPP・脱原発・消費増税凍結を実現する党");
    auto GenzeiNipponHanTPPDatsuGenpatsuWoJitsugenSuruTo = HanTPPDatsugenpatsuShouhizouzeitouketsuWoJitsugenSuruTo.fork(201202, "GenzeiNipponHanTPPDatsuGenpatsuWoJitsugenSuruTo", "減税日本・反TPP・脱原発を実現する党が反TPP・脱原発・消費増税凍結を実現する党から改名");
    GenzeiNipponHanTPPDatsuGenpatsuWoJitsugenSuruTo.merge(201202, GenzeiNippon, "減税日本が減税日本・反TPP・脱原発を実現する党へ合流");

    auto NipponMiraiNoTo = Origin.fork(201201, "NipponMiraiNoTo", "日本未来の党結党");
    NipponMiraiNoTo.merge(201203, KokuminNoSeikatsuGaDaiichi, "国民の生活が第一へ日本未来の党へ合流");
    NipponMiraiNoTo.merge(201202, GenzeiNipponHanTPPDatsuGenpatsuWoJitsugenSuruTo, "減税日本・反TPP・脱原発を実現する党が日本未来の党へ合流");

    auto SeikatsuNoTo = NipponMiraiNoTo.fork(201204, "SeikatsuNoTo", "生活の党が日本未来の党から分裂");
    auto SeikatsuNoToToYamamotoTaroToNakamatachi = SeikatsuNoTo.fork(201401, "SeikatsuNoToToYamamotoTaroToNakamatachi", "生活の党と山本太郎となかまたちが生活の党から改名");
    auto MidoriNoKaze = Origin.fork(201201, "MidoriNoKaze", "みどりの風結党");
    MidoriNoKaze.merge(201202, NipponMiraiNoTo, "日本未来の党がみどりの風へ合流");

    auto TaiyouNoTo14 = Origin.fork(201401, "TaiyouNoTo14", "太陽の党結党");
    JisedaiNoTo.merge(201501, TaiyouNoTo14, "太陽の党が次世代の党へ合流");

    return 0;
}