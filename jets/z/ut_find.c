/* j/6/find.c
**
*/
#include "all.h"

  static u3_noun
  _find_buck(u3_noun van,
             u3_noun sut,
             u3_noun way,
             u3_noun p_heg,
             u3_noun q_heg,
             u3_noun axe,
             u3_noun lon,
             u3_noun gil);

  static u3_noun
  u3qzu_felt(u3_noun van,
             u3_noun sut,
             u3_noun lap)
  {
    u3_noun von = u3i_molt(u3k(van), u3x_sam, u3k(sut), 0);
    u3_noun gat = u3j_hook(von, "felt");

    return u3n_kick_on(u3i_molt(gat, 
                                u3x_sam, 
                                u3k(lap), 
                                0));
  }

  static u3_noun
  u3qzu_fund(u3_noun van,
             u3_noun sut,
             u3_noun way, 
             u3_noun gen)
  {
    u3_noun von = u3i_molt(u3k(van), u3x_sam, u3k(sut), 0);
    u3_noun gat = u3j_hook(von, "fund");

    return u3n_kick_on(u3i_molt(gat, 
                                u3x_sam_2,
                                u3k(way), 
                                u3x_sam_3,
                                u3k(gen), 
                                0));
  }

  static u3_noun
  u3qzu_fine(u3_noun van,
             u3_noun sut,
             u3_noun tor)
  {
    u3_noun von = u3i_molt(u3k(van), u3x_sam, u3k(sut), 0);
    u3_noun gat = u3j_hook(von, "fine");

    return u3n_kick_on(u3i_molt(gat, 
                                u3x_sam, 
                                u3k(tor), 
                                0));
  }

  static u3_noun
  _find_buck_here(u3_noun van,
                  u3_noun sut,
                  u3_noun way,
                  u3_noun p_heg,
                  u3_noun q_heg,
                  u3_noun axe,
                  u3_noun lon,
                  u3_noun gil)
  {
    if ( 0 == p_heg ) {
      return u3nq
        (c3y,
         u3_nul,
         u3nt(u3_nul,
              u3nc(u3_nul, u3k(axe)),
              u3k(lon)),
         u3nc(c3y, u3k(sut)));
    } 
    else {
      return u3nt
        (c3n, c3y, u3qa_dec(p_heg));
    }
  }

  static u3_noun
  _find_join(u3_noun a,
             u3_noun b)
  {
    if ( c3y == u3r_sing(a, b) ) {
      return u3k(a);
    } else {
      return u3kb_weld(u3k(a), u3nc(c3_s2('|', '|'), u3k(b)));
    }
  }
              
  static u3_noun
  _find_buck_lose(u3_noun van,
                  u3_noun sut,
                  u3_noun way,
                  u3_noun p_heg,
                  u3_noun q_heg,
                  u3_noun axe,
                  u3_noun lon,
                  u3_noun gil)
  {
    return u3nt(c3n, c3y, u3k(p_heg));
  }
  static u3_noun
  _find_buck_stop(u3_noun van,
                  u3_noun sut,
                  u3_noun way,
                  u3_noun p_heg,
                  u3_noun q_heg,
                  u3_noun axe,
                  u3_noun lon,
                  u3_noun gil)
  {
    if ( u3_nul == q_heg ) {
      return _find_buck_here(van, sut, way, p_heg, q_heg, axe, lon, gil);
    }
    else {
      return _find_buck_lose(van, sut, way, p_heg, q_heg, axe, lon, gil);
    }
  }

  static u3_noun
  _find_buck_cell(u3_noun van,
                  u3_noun sut,
                  u3_noun way,
                  u3_noun p_heg,
                  u3_noun q_heg,
                  u3_noun axe,
                  u3_noun lon,
                  u3_noun gil)
  {
    u3_noun p_sut, q_sut;

    u3x_cell(u3t(sut), &p_sut, &q_sut);
    {
      if ( u3_nul == q_heg ) {
        return _find_buck_here(van, sut, way, p_heg, q_heg, axe, lon, gil);
      }
      else {
        u3_noun exa = u3qc_peg(axe, 2);
        u3_noun hed = _find_buck(van, p_sut, way, p_heg, q_heg, exa, lon, gil);

        u3z(exa);
        if ( (u3_nul == hed) || (c3y == u3h(hed)) || (c3n == u3h(u3t(hed))) ) {
          return hed;
        }
        else {
          u3_noun exa = u3qc_peg(axe, 3);
          u3_noun tal = _find_buck
            (van, q_sut, way, u3t(u3t(hed)), q_heg, exa, lon, gil);

          u3z(exa);
          u3z(hed);

          return tal;
        }
      }
    }
  }

  static u3_noun
  _find_buck_core(u3_noun van,
                  u3_noun sut,
                  u3_noun way,
                  u3_noun p_heg,
                  u3_noun q_heg,
                  u3_noun axe,
                  u3_noun lon,
                  u3_noun gil)
  {
    u3_noun p_sut, q_sut, pq_sut, qq_sut, rq_sut, prq_sut, qrq_sut;

    u3x_cell(u3t(sut), &p_sut, &q_sut);
    u3x_trel(q_sut, &pq_sut, &qq_sut, &rq_sut);
    u3x_cell(rq_sut, &prq_sut, &qrq_sut);
    {
      if ( u3_nul == q_heg ) {
        return _find_buck_here(van, sut, way, p_heg, q_heg, axe, lon, gil);
      }
      else {
        u3_noun zem = u3qz_loot(u3t(q_heg), qrq_sut);

        if ( (u3_nul != zem) && (0 != p_heg) ) {
          u3_noun ped;

          ped = u3qa_dec(p_heg);
          u3z(p_heg); p_heg = ped;

          u3z(zem);
          zem = u3_nul;
        }

        if ( u3_nul != zem ) {
          u3_noun u_zem = u3t(zem);
          u3_noun pu_zem = u3h(u_zem);
          u3_noun qu_zem = u3t(u_zem);
          u3_noun pqu_zem = u3h(qu_zem);
          u3_noun qqu_zem = u3t(qu_zem);
          u3_noun mut;
          u3_noun pro;

          mut = u3nt(c3__core,
                     u3k(p_sut),
                     u3nt(c3__gold,
                          u3k(qq_sut),
                          u3k(rq_sut)));

          pro = u3nq
            (c3y,
             u3k(pqu_zem),
             u3nc(u3nc(u3_nul, u3k(axe)), u3k(lon)),
             u3nt(c3n,
                  u3qc_peg(2, pu_zem),
                  u3nt(u3nc(mut, u3k(qqu_zem)), u3_nul, u3_nul)));
          
          u3z(zem);
          return pro;
        }
        else {
          u3_noun pec = u3qzu_peel(van, sut, way, pq_sut);
          u3_noun pro;

          if ( c3n == u3h(pec) ) {
            pro = _find_buck_lose(van, sut, way, p_heg, q_heg, axe, lon, gil);
          }
          else if ( c3y == u3t(pec) ) {
            u3_noun exa = u3qc_peg(axe, 3);

            pro = _find_buck(van, p_sut, way, p_heg, q_heg, exa, lon, gil);
            u3z(exa);
          }
          else {
            u3_noun sam = u3qzu_peek(van, p_sut, way, 2);
            u3_noun exa = u3qc_peg(axe, 6);

            pro = _find_buck(van, sam, way, p_heg, q_heg, exa, lon, gil);
            u3z(exa);
            u3z(sam);
          }
          u3z(pec);
          return pro;
        }
      }
    }
  }

  static u3_noun 
  _find_twin(u3_noun van,
             u3_noun hax, 
             u3_noun yor)
  {
    if ( c3y == u3r_sing(hax, yor) ) {
      return u3k(hax);
    }
    else if ( u3_nul == hax ) {
      return u3k(yor);
    }
    else if ( u3_nul == yor ) {
      return u3k(hax);
    }
    else if ( c3n == u3h(hax) ) {
      if ( (c3n != u3h(yor)) ) {
        return u3m_error("find-fork-a");
      }
      else {
        u3_noun p_hax = u3t(hax);                   //  (each @ud {span nock})
        u3_noun p_yor = u3t(yor);                   //  (each @ud {span nock})

        if ( (c3n != u3h(p_hax)) || (c3n != u3h(p_yor)) ) {
          return u3m_error("find-fork-b");
        }
        else {
          u3_noun pp_hax = u3t(p_hax);              //  {span nock}
          u3_noun pp_yor = u3t(p_yor);              //  {span nock}
          u3_noun ppp_hax = u3h(pp_hax);            //  wain
          u3_noun ppp_yor = u3h(pp_yor);            //  wain
          u3_noun qpp_hax = u3t(pp_hax);
          u3_noun qpp_yor = u3t(pp_yor);
          u3_noun pqpp_hax = u3h(qpp_hax);            //  span
          u3_noun pqpp_yor = u3h(qpp_yor);            //  span
          u3_noun qqpp_hax = u3t(qpp_hax);            //  nock
          u3_noun qqpp_yor = u3t(qpp_yor);            //  nock

          if ( c3n == u3r_sing(qqpp_hax, qqpp_yor) ) {
            return u3m_error("find-fork-c");
          }
          return u3nq(c3n,
                      c3n,
                      _find_join(ppp_hax, ppp_yor),
                      u3nc(
                        u3kf_fork(u3nt(u3k(pqpp_hax), u3k(pqpp_yor), u3_nul)),
                        u3k(qqpp_hax)));
        }
      }
    }
    else {
      if ( c3n == u3h(yor) ) {
        return u3m_error("find-fork-d");
      }
      else {
        u3_noun p_hax = u3t(hax);                     //  {wain vein opal}
        u3_noun p_yor = u3t(yor);                     //  {wain vein opal}
        u3_noun pp_hax = u3h(p_hax);                  //  wain
        u3_noun pp_yor = u3h(p_yor);                  //  wain
        u3_noun qp_hax = u3t(p_hax);                  //  {vein opal}
        u3_noun qp_yor = u3t(p_yor);                  //  {vein opal}
        u3_noun pqp_hax = u3h(qp_hax);                //  vein
        u3_noun pqp_yor = u3h(qp_yor);                //  vein
        u3_noun qqp_hax = u3t(qp_hax);                //  opal
        u3_noun qqp_yor = u3t(qp_yor);                //  opal
     
        if ( c3n == u3r_sing(pqp_hax, pqp_yor) ) {
          return u3m_error("find-fork-e");
        }
        else {
          if ( c3y == u3h(qqp_hax) ) {
            if ( c3y != u3h(qqp_yor) ) {
              return u3m_error("find-fork-f");
            } else {
              u3_noun pqqp_hax = u3t(qqp_hax);        //  span
              u3_noun pqqp_yor = u3t(qqp_yor);        //  span

              return 
                u3nq(c3y,
                     _find_join(pp_hax, pp_yor),
                     u3k(pqp_hax),
                     u3nc(c3y, u3kf_fork
                       (u3nt(u3k(pqqp_hax), u3k(pqqp_yor), u3_nul))));
            }
          }
          else if ( c3n != u3h(qqp_yor) ) {
            return u3m_error("find-fork-g");
          } else {
            u3_noun pqqp_hax = u3h(u3t(qqp_hax));     //  axis
            u3_noun pqqp_yor = u3h(u3t(qqp_yor));     //  axis
            u3_noun qqqp_hax = u3t(u3t(qqp_hax));     //  (set {span foot})
            u3_noun qqqp_yor = u3t(u3t(qqp_yor));     //  (set {span foot})

            if ( c3n == u3r_sing(pqqp_hax, pqqp_yor) ) {
              return u3m_error("find-fork-h");
            } else {
              return 
                u3nq(c3y, 
                     u3_nul,
                     u3k(pqp_hax),
                     u3nt(c3n, u3k(pqqp_hax), u3qdi_uni(qqqp_hax, qqqp_yor)));
            }
          }
        }
      }
    }
    // error: { return u3m_error("find-fork"); }
  }

  static u3_noun
  _find_buck_fork_twin(u3_noun van, u3_noun wiz)
  {
    if ( u3_nul == wiz ) {
      return u3_nul;
    } 
    else if ( u3_nul == u3t(wiz) ) {
      return u3k(u3h(wiz));
    }
    else {
      u3_noun hax = u3k(u3h(wiz));
      u3_noun yor = _find_buck_fork_twin(van, u3t(wiz));
      u3_noun fid = _find_twin(van, hax, yor);

      u3z(hax);
      u3z(yor);

      return fid;
    }
  }

  static u3_noun 
  _find_buck_fork_turn(u3_noun van,
                       u3_noun yed,
                       u3_noun way,
                       u3_noun p_heg,
                       u3_noun q_heg,
                       u3_noun axe,
                       u3_noun lon,
                       u3_noun gil)
  {
    if ( u3_nul == yed ) {
      return u3_nul;
    } 
    else {
      u3_noun fid = _find_buck(van, u3h(yed), way, p_heg, q_heg, axe, lon, gil);

      return u3nc
        (fid,
         _find_buck_fork_turn
            (van, u3t(yed), way, p_heg, q_heg, axe, lon, gil));
    }
  }
  
  static u3_noun
  _find_buck_fork(u3_noun van,
                  u3_noun sut,
                  u3_noun way,
                  u3_noun p_heg,
                  u3_noun q_heg,
                  u3_noun axe,
                  u3_noun lon,
                  u3_noun gil)
  {
    u3_noun p_sut = u3t(sut);
    u3_noun yed = u3qdi_tap(p_sut, u3_nul);
    u3_noun wiz;
    u3_noun ret;

    wiz = _find_buck_fork_turn(van, yed, way, p_heg, q_heg, axe, lon, gil);
    u3z(yed);
 
    ret = _find_buck_fork_twin(van, wiz);
    u3z(wiz);
   
    return ret;
  }

  static u3_noun
  _find_buck_face_next(u3_noun van,
                       u3_noun sut,
                       u3_noun q_sut,
                       u3_noun qp_sut,
                       u3_noun way,
                       u3_noun p_heg,
                       u3_noun q_heg,
                       u3_noun axe,
                       u3_noun lon,
                       u3_noun gil)
  {
    if ( u3_nul == qp_sut ) {
    // if ( 1 ) {
      u3_noun nol = u3nc(u3_nul, u3k(lon));
      u3_noun ret = _find_buck(van, q_sut, way, p_heg, q_heg, axe, nol, gil);
      u3z(nol);
      return ret;
    }
    else {
      u3_noun iqp_sut = u3h(qp_sut);      //  twig
      u3_noun tiv = u3qzu_mint            //  (pair span nock)
        (van, q_sut, c3__noun, iqp_sut);
      u3_noun tqp_sut = u3t(qp_sut);      //  (list twig)
      u3_noun p_tiv = u3h(tiv);           //  span
      u3_noun q_tiv = u3t(tiv);           //  nock
      u3_noun fid = _find_buck            //  pony
        (van, p_tiv, way, p_heg, q_heg, 1, u3_nul, u3_nul);

      if ( u3_nul == fid ) {
        u3z(tiv);
        return u3_nul;
      }
      else if ( (c3n == u3h(fid)) && (c3y == u3h(u3t(fid))) ) {
        u3_noun ret;

        ret = _find_buck_face_next
         (van, sut, q_sut, tqp_sut, way, u3t(u3t(fid)), q_heg, axe, lon, gil);
        u3z(fid);
        u3z(tiv);
        return ret;
      }
      else {
        u3_noun tor;                      //  port
        u3_noun vat;                      //  (pair span nock)
        u3_noun ret;
        u3_noun dog = u3nc(0, u3k(axe));  //  nock
        u3_noun wan;

        if ( c3y == u3h(fid) ) {
          wan = u3k(u3h(u3t(fid)));
          tor = u3nc(c3y, u3k(u3t(u3t(fid))));
        } else {
          wan = u3k(u3h(u3t(u3t(fid))));
          tor = u3nc(c3n, u3k(u3t(u3t(fid))));
        }
        u3z(fid);

        vat = u3qzu_fine(van, sut, tor);
        u3z(tor);

        ret = u3nq
          (c3n, 
           c3n, 
           wan,
           u3nc(u3k(u3h(vat)), u3qz_comb(u3qz_comb(dog, q_tiv), u3t(vat))));

        u3z(vat);
        u3z(dog);
        u3z(tiv);

        return ret;
      }
    }
  }

  static u3_noun
  _find_buck_face(u3_noun van,
                  u3_noun sut,
                  u3_noun way,
                  u3_noun p_heg,
                  u3_noun q_heg,
                  u3_noun axe,
                  u3_noun lon,
                  u3_noun gil)
  {
    u3_noun p_sut, q_sut;
    u3_noun pp_sut, qp_sut;

    u3x_cell(u3t(sut), &p_sut, &q_sut);
    u3x_cell(p_sut, &pp_sut, &qp_sut);

    if ( u3_nul == q_heg ) {
      return _find_buck_here(van, q_sut, way, p_heg, q_heg, axe, lon, gil);
    }
    else {
      u3_noun uq_heg = u3t(q_heg);          //  term

      if ( c3y == u3ud(qp_sut) ) {
        if ( c3y == u3r_sing(qp_sut, uq_heg) ) {
          return _find_buck_here(van, q_sut, way, p_heg, q_heg, axe, lon, gil);
        } 
        else {
          return _find_buck_lose(van, sut, way, p_heg, q_heg, axe, lon, gil);
        }
      }
      else {
        u3_noun pqp_sut = u3h(qp_sut);        //  (map term {wain (unit twig)})
        u3_noun qqp_sut = u3t(qp_sut);        //  (list (pair span nock))
        u3_noun tyr = u3qdb_get(pqp_sut, uq_heg);  //  (unit {wain (unit twig)})

        if ( u3_nul == tyr ) {
          return _find_buck_face_next
            (van, sut, q_sut, qqp_sut, way, p_heg, q_heg, axe, lon, gil);
        }
        else {
          u3_noun u_tyr = u3t(tyr);       //  (pair wain (unit twig))
          u3_noun pu_tyr = u3h(u_tyr);
          u3_noun qu_tyr = u3t(u_tyr);

          if ( u3_nul == qu_tyr ) {
            u3_noun nol = u3nc(u3_nul, u3k(lon));
            u3_noun dep = u3qa_inc(p_heg);
            u3_noun ret = _find_buck
                              (van, q_sut, way, dep, q_heg, axe, nol, gil);

            u3z(dep);
            u3z(nol);
            u3z(tyr);
            return ret;
          }
          else {
            u3_noun uqu_tyr = u3t(qu_tyr);
            u3_noun tor = u3qzu_fund(van, sut, way, uqu_tyr);

            if ( c3y == u3h(tor) ) {
              u3_noun p_tor = u3t(tor);      //  (pair vein opal)
              u3_noun pp_tor = u3h(p_tor);    //  vein
              u3_noun qp_tor = u3t(p_tor);    //  opal
              u3_noun nol =                       //  vein
                u3nt(u3_nul, u3nc(u3_nul, u3k(axe)), u3k(lon));
              u3_noun ret;
 
              ret = u3nq(c3y, u3_nul, u3qb_weld(pp_tor, nol), u3k(qp_tor));
              u3z(nol);
              u3z(tor); 
              u3z(tyr);
              return ret;
            }
            else {
              u3_noun p_tor = u3t(tor);      // (pair span nock)
              u3_noun pp_tor = u3h(p_tor);    //  span
              u3_noun qp_tor = u3t(p_tor);    //  nock
              u3_noun dog = u3nc(0, u3k(axe));    //  nock
              u3_noun ret;

              ret = u3nq(c3n, 
                         c3n, 
                         u3k(pu_tyr),
                         u3nc(u3k(pp_tor), u3qz_comb(dog, qp_tor)));
              u3z(dog);
              u3z(tor); 
              u3z(tyr);

              return ret;
            }
          }
        }
      }
    }
  }

  static u3_noun
  _find_buck(u3_noun van,
             u3_noun sut,
             u3_noun way,
             u3_noun p_heg,
             u3_noun q_heg,
             u3_noun axe,
             u3_noun lon,
             u3_noun gil)
  {
    if ( c3n == u3du(sut) ) switch ( sut ) {
      default: return u3m_bail(c3__fail);

      case c3__noun: {
        // fprintf(stderr, "noun\r\n");
        return _find_buck_stop(van, sut, way, p_heg, q_heg, axe, lon, gil);
      }
      case c3__void: {
        // fprintf(stderr, "void\r\n");
        return _find_buck_stop(van, sut, way, p_heg, q_heg, axe, lon, gil);
      }
    }
    else switch ( u3h(sut) ) {
      default: return u3m_bail(c3__fail);

      case c3__atom: 
      {
        // fprintf(stderr, "atom\r\n");
        return _find_buck_stop(van, sut, way, p_heg, q_heg, axe, lon, gil);
      }
      case c3__cell: 
      {
        // fprintf(stderr, "cell\r\n");
        return _find_buck_cell(van, sut, way, p_heg, q_heg, axe, lon, gil);
      }
      case c3__core:
      {
        // fprintf(stderr, "core\r\n");
        return _find_buck_core(van, sut, way, p_heg, q_heg, axe, lon, gil);
      }
      case c3__help:
      {
        u3_noun fop = u3qzu_repo(van, sut);
        u3_noun pro = _find_buck(van, fop, way, p_heg, q_heg, axe, lon, gil);
        u3z(fop);
        return pro;
      }
      case c3__face:
      {
        // fprintf(stderr, "face\r\n");
        return _find_buck_face(van, sut, way, p_heg, q_heg, axe, lon, gil);
      }
      case c3__fork:
      {
        // fprintf(stderr, "fork\r\n");
        return _find_buck_fork(van, sut, way, p_heg, q_heg, axe, lon, gil);
      }
      case c3__hold:
      {
        // fprintf(stderr, "hold\r\n");
        if ( (c3y == u3qdi_has(gil, sut)) ) {
          return u3_nul;
        }
        else {
          u3_noun zoc = u3qdi_put(gil, sut);
          u3_noun fop = u3qzu_repo(van, sut);
          u3_noun pro = _find_buck(van, fop, way, p_heg, q_heg, axe, lon, zoc);

          u3z(fop);
          u3z(zoc);

          return pro;
        }
      }
    }
  }


  static u3_noun
  _find_limb(u3_noun van,
             u3_noun sut,                  //  span
             u3_noun way,                  //  ?(%read %rite %free %both)
             u3_noun i_hyp,                //  limb
             u3_noun p_mor)                //  {wain palo}
  {
    u3_noun qp_mor = u3t(p_mor);          //  palo
    u3_noun pqp_mor = u3h(qp_mor);        //  vein
    u3_noun qqp_mor = u3t(qp_mor);        //  opal
    {
      u3_noun ref    = u3qzu_felt(van, sut, qqp_mor);
      u3_noun lon    = u3k(pqp_mor);
      u3_noun heg    = (c3y == u3du(i_hyp))
                         ? u3k(i_hyp)
                         : u3nq(c3n, 0, u3_nul, u3k(i_hyp));
      u3_noun ret;
      
      if ( c3y == u3h(heg) ) {
        u3_noun p_heg = u3t(heg);         //  axis

        ret = u3nq
          (c3y,
           u3_nul,
           u3nc(u3nc(u3_nul, u3k(p_heg)), u3k(lon)),
           u3nc(c3y, u3qzu_peek(van, ref, way, p_heg)));
      }
      else {
        u3_noun p_heg = u3h(u3t(heg));    //  @ud
        u3_noun q_heg = u3t(u3t(heg));    //  (unit term)

        ret = _find_buck
                (van, ref, way, p_heg, q_heg, 1, lon, u3_nul);
      }
      u3z(heg);
      u3z(lon);
      u3z(ref);

      return ret;
    }
  }

  static u3_noun
  _find_pony(u3_noun van,
             u3_noun sut,
             u3_noun way,
             u3_noun hyp)
  {
    if ( u3_nul == hyp ) {
      return u3nq(c3y, u3_nul, u3_nul, u3nc(c3y, u3k(sut)));
    }
    else {
      u3_noun i_hyp = u3h(hyp);
      u3_noun t_hyp = u3t(hyp);
      u3_noun mor = _find_pony(van, sut, way, t_hyp);

      if ( c3n == u3h(mor) ) {
        u3_noun p_mor = u3t(mor);

        if ( c3y == u3h(p_mor) ) {
          return mor;
        } 
        else {
          u3_noun pp_mor = u3t(p_mor);      //  {wain span nock}
          u3_noun ppp_mor = u3h(pp_mor);
          u3_noun qpp_mor = u3t(pp_mor);
          u3_noun pqpp_mor = u3h(qpp_mor);    //  span
          u3_noun qqpp_mor = u3t(qpp_mor);    //  nock
          u3_noun gen = u3nt(c3__wing, u3k(i_hyp), u3_nul);
          u3_noun fex = u3qzu_mint(van, pqpp_mor, c3__noun, gen);
          u3_noun ret = u3nq(c3n, 
                             c3n,
                             u3k(ppp_mor),
                             u3nc(u3k(u3h(fex)),
                                  u3qz_comb(qqpp_mor, u3t(fex))));
          u3z(fex);
          u3z(gen);
          u3z(mor);

          return ret;
        }
      }
      else {
        u3_noun p_mor = u3t(mor);
        u3_noun ret = _find_limb(van, sut, way, i_hyp, p_mor);

        u3z(mor);
        return ret;
      }
    }
  }

  static u3_noun
  _cqzu_fond(u3_noun van,
             u3_noun sut,
             u3_noun way,
             u3_noun hyp)
  {
    u3_noun taf;
   
    taf = _find_pony(van, sut, way, hyp);

    return taf;
  }

  u3_noun
  _cqzu_find(u3_noun van,
             u3_noun sut,
             u3_noun way,
             u3_noun hyp)
  {
    u3_noun taf = _find_pony(van, sut, way, hyp);

    if ( u3_nul == taf ) {
      goto error;
    }
    else {
      if ( c3y == u3h(taf) ) {
        u3_noun fat = u3nc(c3y, u3k(u3t(u3t(taf))));
        
        u3z(taf);
        return fat;
      }
      else {
        if ( c3n == u3h(u3t(taf)) ) {
          u3_noun fat = u3nc(c3n, u3k(u3t(u3t(u3t(taf)))));

          u3z(taf); 
          return fat;
        }
        else {
          goto error;
        }
      }
    }
    error: {
      u3m_p("wing", hyp);

      return u3m_error("find");
    }
  }

/* boilerplate
*/
  u3_noun
  u3wzu_find(u3_noun cor)
  {
    u3_noun sut, way, hyp, van;

    if ( (c3n == u3r_mean(cor, u3x_sam_2, &way,
                               u3x_sam_3, &hyp,
                               u3x_con, &van,
                               0)) ||
         (u3_none == (sut = u3r_at(u3x_sam, van))) )
    {
      return u3m_bail(c3__fail);
    } else {
      return _cqzu_find(van, sut, way, hyp);
    }
  }

  u3_noun
  u3qzu_find(u3_noun van,
             u3_noun sut,
             u3_noun way,
             u3_noun hyp)
  {
    c3_m    fun_m = 145 + c3__find + ((!!u3r_at(u3qzu_van_vet, van)) << 8);
    u3_noun pro   = u3z_find_3(fun_m, sut, way, hyp);

    if ( u3_none != pro ) {
      return pro;
    }
    else {
      pro = _cqzu_find(van, sut, way, hyp);

      return u3z_save_3(fun_m, sut, way, hyp, pro);
    }
  }

/* boilerplate
*/
  u3_noun
  u3wzu_fond(u3_noun cor)
  {
    u3_noun sut, way, hyp, van;

    if ( (c3n == u3r_mean(cor, u3x_sam_2, &way,
                               u3x_sam_3, &hyp,
                               u3x_con, &van,
                               0)) ||
         (u3_none == (sut = u3r_at(u3x_sam, van))) )
    {
      return u3m_bail(c3__fail);
    } else {
      return _cqzu_fond(van, sut, way, hyp);
    }
  }

  u3_noun
  u3qzu_fond(u3_noun van,
             u3_noun sut,
             u3_noun way,
             u3_noun hyp)
  {
    c3_m    fun_m = 145 + c3__fond + ((!!u3r_at(u3qzu_van_vet, van)) << 8);
    u3_noun pro   = u3z_find_3(fun_m, sut, way, hyp);

    if ( u3_none != pro ) {
      return pro;
    }
    else {
      pro = _cqzu_fond(van, sut, way, hyp);

      return u3z_save_3(fun_m, sut, way, hyp, pro);
    }
  }